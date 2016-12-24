#include "Game.h"
#include "Version.h"


const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game() : mWindow(sf::VideoMode(), "Magic Craft", winMode::Fullscreen), mIsPaused(false), mStateStack(State::Context(mWindow, mTexture, mFont, mPlayer)), mPlayer()
{
	setlocale(LC_ALL, "rus");

	mFont.load(Fonts::Main ,"arial.ttf");
	mTexture.load(Textures::TitleScreen, "image/titlescreen.png");
	mTexture.load(Textures::ButtonNormal, "image/ButtonNormal.png");
	mTexture.load(Textures::ButtonSelected, "image/ButtonSelected.png");
	mTexture.load(Textures::ButtonPressed, "image/ButtonPressed.png");

	mStatisticsText.setFont(mFont.get(Fonts::Main));
	mStatisticsText.setPosition(1790.f, 5.f);
	mStatisticsText.setCharacterSize(10);

	registerStates();
	mStateStack.pushState(States::Title);
}

Game::~Game()
{

}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processEvent();

			
			update(TimePerFrame);
		}

		updateStatistics(elapsedTime);
		render();
	}
}

void Game::processEvent()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		mStateStack.handleEvent(event);
	}
}

void Game::update(sf::Time deltaTime)
{
	mStateStack.update(deltaTime);
}

void Game::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString(
			"Frames / Second = " + toString(mStatisticsNumFrames) + "\n" +
			"Time / Update = " + toString(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us"
			);

		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}

}

void Game::registerStates()
{
	mStateStack.registerState<TitleState>(States::Title);
	mStateStack.registerState<MenuState>(States::Menu);
	mStateStack.registerState<SettingsState>(States::Setting);
	mStateStack.registerState<CreditState>(States::Credits);
	mStateStack.registerState<LoadingState>(States::Loading);
	mStateStack.registerState<GameState>(States::Game);
}

void Game::render()
{
	mWindow.clear(sf::Color(100, 100, 150));

	mStateStack.draw();

	mWindow.setView(mWindow.getDefaultView());

	if (name == "alpha: ")
		mWindow.draw(mStatisticsText);

	mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::Escape) {
		mWindow.close();
	}
	else if (key == sf::Keyboard::F5) {
		mWindow.setPosition(sf::Vector2i(0, 0));
	}
}
