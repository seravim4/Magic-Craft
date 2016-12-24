#pragma once
#include "Command.h"
#include <SFML\Window\Event.hpp>
#include "CommandQueue.h"

#include <map>
#include <string>
#include <algorithm>
#include "Foreach.h"

using namespace std::placeholders;

class Player
{
public:
	
	enum Action
	{
		Key1,
		Key2,
		Key3,
		Key4,
		Key5,
		Key6,
		Key7,
		Key8,
		Key9,
		Key0,
		ActionCount
	};

public:

						Player();

	void				handleEvent(const sf::Event& event, CommandQueue& commands);
	void				handleRealtimeInput(CommandQueue& commands);

	void				assignKey(Action action, sf::Keyboard::Key key);
	sf::Keyboard::Key	getAssignedKey(Action action) const;

private:

	void				initializeActions();
	static bool			isRealtimeAction(Action action);

private:

	std::map<sf::Keyboard::Key, Action>  mKeyBinding;
	std::map<Action, Command>			 mActionBinding;
};

