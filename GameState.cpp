#include "GameState.h"
#include "cButton.h"
#include "Label.h"
#include "Points.h"
#include "Command.h"
#include "CommandQueue.h"
#include "Player.h"
#include <sstream>

GameState::GameState(StateStack & stack, State::Context context) : State(stack, context), mWorld(*context.window), mGUIContainer(), mPlayer(*context.players)
{


	tKey1.setFont(context.fonts->get(Fonts::Main));
	tKey1.setCharacterSize(12);
	tKey1.setColor(sf::Color::Black);
	tKey1.setPosition(1005, 1120);
	tKey1.setString("1");
	
	tKey2.setFont(context.fonts->get(Fonts::Main));
	tKey2.setCharacterSize(12);
	tKey2.setColor(sf::Color::Black);
	tKey2.setPosition(1055, 1120);
	tKey2.setString("2");
	
	tKey3.setFont(context.fonts->get(Fonts::Main));
	tKey3.setCharacterSize(12);
	tKey3.setColor(sf::Color::Black);
	tKey3.setPosition(1105, 1120);
	tKey3.setString("3");

	tKey4.setFont(context.fonts->get(Fonts::Main));
	tKey4.setCharacterSize(12);
	tKey4.setColor(sf::Color::Black);
	tKey4.setPosition(1155, 1120);
	tKey4.setString("4");
	
	tKey5.setFont(context.fonts->get(Fonts::Main));
	tKey5.setCharacterSize(12);
	tKey5.setColor(sf::Color::Black);
	tKey5.setPosition(1205, 1120);
	tKey5.setString("5");
	
	tKey6.setFont(context.fonts->get(Fonts::Main));
	tKey6.setCharacterSize(12);
	tKey6.setColor(sf::Color::Black);
	tKey6.setPosition(1255, 1120);
	tKey6.setString("6");
	
	tKey7.setFont(context.fonts->get(Fonts::Main));
	tKey7.setCharacterSize(12);
	tKey7.setColor(sf::Color::Black);
	tKey7.setPosition(1305, 1120);
	tKey7.setString("7");
	
	tKey8.setFont(context.fonts->get(Fonts::Main));
	tKey8.setCharacterSize(12);
	tKey8.setColor(sf::Color::Black);
	tKey8.setPosition(1355, 1120);
	tKey8.setString("8");
	
	tKey9.setFont(context.fonts->get(Fonts::Main));
	tKey9.setCharacterSize(12);
	tKey9.setColor(sf::Color::Black);
	tKey9.setPosition(1405, 1120);
	tKey9.setString("9");
	
	tKey0.setFont(context.fonts->get(Fonts::Main));
	tKey0.setCharacterSize(12);
	tKey0.setColor(sf::Color::Black);
	tKey0.setPosition(1455, 1120);
	tKey0.setString("0");
}

void GameState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());

	mWorld.draw();
	window.draw(mGUIContainer);
	
	window.draw(tKey1);
	window.draw(tKey2);
	window.draw(tKey3);
	window.draw(tKey4);
	window.draw(tKey5);
	window.draw(tKey6);
	window.draw(tKey7);
	window.draw(tKey8);
	window.draw(tKey9);
	window.draw(tKey0);
}

bool GameState::update(sf::Time dt)
{
	mWorld.update(dt);

	return true;
}

bool GameState::handleEvent(const sf::Event & event)
{
	sf::RenderWindow& window = *getContext().window;
	
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
	pos = window.mapPixelToCoords(pixelPos);

	mGUIContainer.handleEvent(event, window);

	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
	{
		requestStackPop();
		requestStackPush(States::Menu);
	}

	return true;
}
