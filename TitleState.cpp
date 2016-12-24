#include "TitleState.h"
#include "Utility.h"

TitleState::TitleState(StateStack & stack, State::Context context) : 

State(stack, context)
, mText()
, mShowText(true)
, mTextEffectTime(sf::Time::Zero)
{
	mBackgroundSprite.setTexture(context.textures->get(Textures::TitleScreen));

	mText.setFont(context.fonts->get(Fonts::Main));
	mText.setCharacterSize(30);
	mText.setColor(sf::Color(255, 255, 255, 200));
	mText.setString("Press Space key to start");
	centerOrigin(mText);
	mText.setPosition(900, 850);
}

void TitleState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mBackgroundSprite);

	if (mShowText)
		window.draw(mText);
}

bool TitleState::update(sf::Time dt)
{
	mTextEffectTime += dt;

	if (mTextEffectTime >= sf::seconds(0.7f))
	{
		mShowText = !mShowText;
		mTextEffectTime = sf::Time::Zero;
	}

	return true;
}

bool TitleState::handleEvent(const sf::Event & event)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
	{
		requestStackPop();
		requestStackPush(States::Menu);
	}

	return true;
}
