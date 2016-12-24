#include "Player.h"

Player::Player()
{
	mKeyBinding[sf::Keyboard::Num1] = Key1;
	mKeyBinding[sf::Keyboard::Num2] = Key2;
	mKeyBinding[sf::Keyboard::Num3] = Key3;
	mKeyBinding[sf::Keyboard::Num4] = Key4;
	mKeyBinding[sf::Keyboard::Num5] = Key5;
	mKeyBinding[sf::Keyboard::Num6] = Key6;
	mKeyBinding[sf::Keyboard::Num7] = Key7;
	mKeyBinding[sf::Keyboard::Num8] = Key8;
	mKeyBinding[sf::Keyboard::Num9] = Key9;
	mKeyBinding[sf::Keyboard::Num0] = Key0;

	initializeActions();

	FOREACH(auto& pair, mActionBinding)
		pair.second.category = Category::PlayerCraft;
}

void Player::handleEvent(const sf::Event & event, CommandQueue & commands)
{
	if (event.type == sf::Event::KeyPressed)
	{
		auto found = mKeyBinding.find(event.key.code);
		if (found != mKeyBinding.end() && !isRealtimeAction(found->second))
			commands.push(mActionBinding[found->second]);
	}
}

void Player::handleRealtimeInput(CommandQueue & commands)
{
	FOREACH(auto pair, mKeyBinding)
	{
		if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
			commands.push(mActionBinding[pair.second]);
	}
}

void Player::assignKey(Action action, sf::Keyboard::Key key)
{
	for (auto itr = mKeyBinding.begin(); itr != mKeyBinding.end(); )
	{
		if (itr->second == action)
			mKeyBinding.erase(itr++);
		else
			++itr;
	}

	mKeyBinding[key] = action;
}

sf::Keyboard::Key Player::getAssignedKey(Action action) const
{
	FOREACH(auto pair, mKeyBinding)
	{
		if (pair.second == action)
			return pair.first;
	}

	return sf::Keyboard::Unknown;
}

void Player::initializeActions()
{

}

bool Player::isRealtimeAction(Action action)
{
	switch (action)
	{
	case Key1:
	case Key2:
	case Key3:
	case Key4:
	case Key5:
	case Key6:
	case Key7:
	case Key8:
	case Key9:
	case Key0:
		return true;

	default:
		return false;
	}
}
