#pragma once
#include "stdafx.h"
#include "TextureHolder.h"
#include "World.h"
#include "Console.h"
#include "FontHolder.h"
#include "State.h"
#include "StateIdentifier.h"
#include "StateStack.h"
#include "GameState.h"
#include "TitleState.h"
#include "MenuState.h"
#include "SettingsState.h"
#include "LoadingState.h"
#include "CreditState.h"
#include "MusicPlayer.h"
#include "Player.h"

class Game : private sf::NonCopyable
{
public:
			Game();
			~Game();

	void    run();

private:

	void	processEvent();
	void	update(sf::Time deltaTime);
	void	updateStatistics(sf::Time elapsedTime);

	void	registerStates();
	void	render();
	void	handlePlayerInput(sf::Keyboard::Key key, bool isPressed);


private:
	
	enum winMode
	{
		Fullscreen = sf::Style::Fullscreen,
		Close      = sf::Style::Close,
		Default	   = sf::Style::Default,
		None       = sf::Style::None,
		Resize	   = sf::Style::Resize,
		Titlebar   = sf::Style::Titlebar
	};

	sf::RenderWindow						  mWindow;
	StateStack								  mStateStack;

	static const sf::Time					  TimePerFrame;
	bool									  mIsPaused;

private:

	FontHolder								  mFont;
	TextureHolder							  mTexture;
	Player									  mPlayer;
	sf::Text								  mStatisticsText;
	sf::Time								  mStatisticsUpdateTime;
	std::size_t								  mStatisticsNumFrames;
};
