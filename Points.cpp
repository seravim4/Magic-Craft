#include "Points.h"

GUI::Points::Points(const FontHolder & fonts, const TextureHolder & textures) :
	mCallback(),
	mNormalTexture(textures.get(Textures::Point)),
	mSelectedTexture(textures.get(Textures::SelectPoint)),
	mPressedTexture(textures.get(Textures::ActivePoint)),
	mSprite(),
	mText("", fonts.get(Fonts::Main), 16),
	mIsToggle(false),
	mIsSelection(false),
	foo(false)
{
	mSprite.setTexture(mNormalTexture);

	sf::FloatRect bounds = mSprite.getLocalBounds();
	mText.setPosition(bounds.width / 2.f, bounds.height / 2.f);
}

void GUI::Points::setCallback(Callback callback)
{
	mCallback = std::move(callback);
}

void GUI::Points::setText(const std::string & text)
{
	mText.setString(text);

	sf::FloatRect bounds = mText.getLocalBounds();
	mText.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}

void GUI::Points::setToggle(bool flag)
{
	mIsToggle = flag;
}

bool GUI::Points::isSelectable() const
{
	return true;
}

void GUI::Points::select()
{
	Component::select();

	mSprite.setTexture(mSelectedTexture);
}

void GUI::Points::activate()
{
	Component::activate();

	if (mIsToggle)
		mSprite.setTexture(mPressedTexture);

	if (mCallback)
		mCallback();

	if (!mIsToggle)
		deactivate();

	foo = true;
	
	if (foo)
	{
		
		deactivate();
		mSprite.setTexture(mPressedTexture);
	}

	
}

void GUI::Points::deactivate()
{
	Component::deactivate();

	if (mIsToggle)
	{
		if (isSelected())
			mSprite.setTexture(mSelectedTexture);
	}

	
}

void GUI::Points::deselect()
{
	Component::deselect();

	mSprite.setTexture(mNormalTexture);
}

void GUI::Points::handleEvent(const sf::Event& event, sf::RenderWindow& window)
{
	
}

void GUI::Points::update(const sf::Event & event, sf::Vector2f pos)
{
}

void GUI::Points::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(mSprite, states);
}
