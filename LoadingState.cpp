#include "LoadingState.h"

#include "TextureHolder.h"
#include "FontHolder.h"
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\View.hpp>

LoadingState::LoadingState(StateStack& stack, Context context)
	: State(stack, context)
	, mBackgroundSprite()
{
	sf::RenderWindow& window = *getContext().window;
	sf::Font& font = context.fonts->get(Fonts::Main);
	sf::Vector2f viewSize = window.getView().getSize();

	mElapsedTime.restart();

	mLoadingText.setFont(font);
	mLoadingText.setColor(sf::Color(255, 255, 255));
	mLoadingText.setString("Loading Resources...");
	sf::FloatRect bounds = mLoadingText.getLocalBounds();
	mLoadingText.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
	mLoadingText.setPosition(viewSize.x / 2.f, 800);

	sf::Texture& texture = context.textures->get(Textures::TitleScreen);
	mBackgroundSprite.setTexture(texture);

	mProgressBarBackground.setFillColor(sf::Color::White);
	mProgressBarBackground.setSize(sf::Vector2f(500, 10));
	mProgressBarBackground.setPosition(700, mLoadingText.getPosition().y + 40);

	mProgressBar.setFillColor(sf::Color(100, 100, 100));
	mProgressBar.setSize(sf::Vector2f(200, 10));
	mProgressBar.setPosition(700, mLoadingText.getPosition().y + 40);

	setComplection(0.f);

	mLoadingTask.execute();
}

void LoadingState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.setView(window.getDefaultView());

	window.draw(mBackgroundSprite);
	window.draw(mLoadingText);
	window.draw(mProgressBarBackground);
	window.draw(mProgressBar);
}

bool LoadingState::update(sf::Time dt)
{
	if (mLoadingTask.isFinished())
	{
		requestStackPop();
		requestStackPush(States::Game);
	}
	else
	{
		setComplection(mLoadingTask.getComplection());
	}
	return true;
}

bool LoadingState::handleEvent(const sf::Event& event)
{
	return true;
}

void LoadingState::setComplection(float percent)
{
	if (percent > 1.f) 
		percent = 1.f;

	mProgressBar.setSize(sf::Vector2f(mProgressBarBackground.getSize().x * percent, mProgressBar.getSize().y));
}
