#include "cButton.h"

GUI::cButton::cButton(const FontHolder & fonts, const TextureHolder & textures) : 
	mCallback(),
	mNormalTexture(textures.get(Textures::ButtonNormal)),
	mSelectedTexture(textures.get(Textures::ButtonSelected)),
	mPressedTexture(textures.get(Textures::ButtonPressed)),
	mSprite(),
	mText("", fonts.get(Fonts::Main), 16),
	mIsToggle(false),
	mIsSelection(false)
{
	mSprite.setTexture(mNormalTexture);

	sf::FloatRect bounds = mSprite.getLocalBounds();
	mText.setPosition(bounds.width / 2.f, bounds.height / 2.f);
}

void GUI::cButton::setCallback(Callback callback)
{
	mCallback = std::move(callback);
}

void GUI::cButton::setText(const std::string & text)
{
	mText.setString(text);

	sf::FloatRect bounds = mText.getLocalBounds();
	mText.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}

void GUI::cButton::setToggle(bool flag)
{
	mIsToggle = flag;
}

bool GUI::cButton::isSelectable() const
{
	return true;
}

void GUI::cButton::select()
{
	Component::select();

	mSprite.setTexture(mSelectedTexture);
}

void GUI::cButton::activate()
{
	Component::activate();

	if (mIsToggle)
		mSprite.setTexture(mPressedTexture);

	if (mCallback)
		mCallback();

	if (!mIsToggle)
		deactivate();
}

void GUI::cButton::deactivate()
{
	Component::deactivate();

	if (mIsToggle)
	{
		if (isSelected())
			mSprite.setTexture(mSelectedTexture);
		else
			mSprite.setTexture(mNormalTexture);
	}
}

void GUI::cButton::deselect()
{
	Component::deselect();

	mSprite.setTexture(mNormalTexture);
}

void GUI::cButton::handleEvent(const sf::Event& event, sf::RenderWindow& window)
{

}

void GUI::cButton::update(const sf::Event & event, sf::Vector2f pos)
{
}

void GUI::cButton::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(mSprite, states);
	target.draw(mText, states);
}
