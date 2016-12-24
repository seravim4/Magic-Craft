#pragma once
#include "State.h"
#include "StateStack.h"
#include "StateIdentifier.h"
#include "stdafx.h"
#include "World.h"
#include "Container.h"
#include "Player.h"


class GameState : public State
{
public:
					GameState(StateStack& stack, State::Context context);

	virtual	void	draw();
	virtual bool	update(sf::Time dt);
	virtual bool	handleEvent(const sf::Event& event);

private:

	World				mWorld;
	Player&				mPlayer;
	GUI::Container		mGUIContainer;
	sf::Vector2f		pos;

	sf::Text			tKey1;
	sf::Text			tKey2;
	sf::Text			tKey3;
	sf::Text			tKey4;
	sf::Text			tKey5;
	sf::Text			tKey6;
	sf::Text			tKey7;
	sf::Text			tKey8;
	sf::Text			tKey9;
	sf::Text			tKey0;
};

