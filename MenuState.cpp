#include "MenuState.h"
#include "cButton.h"
#include "TextureHolder.h"
#include "FontHolder.h"
#include "SFML\Graphics\RenderWindow.hpp"
#include "SFML\Graphics\View.hpp"
#include "Version.h"





MenuState::MenuState(StateStack& stack, Context context)
	: State(stack, context)
	, mGUIContainer()
{
	sf::Texture& texture = context.textures->get(Textures::TitleScreen);
	mBackgroundSprite.setTexture(texture);

	mVersion.setFont(context.fonts->get(Fonts::Main));
	mVersion.setCharacterSize(10);
	mVersion.setColor(sf::Color::White);
	mVersion.setPosition(10, 1050);
	mVersion.setString(name + toString(version));

	auto playButton = std::make_shared<GUI::cButton>(*context.fonts, *context.textures);
	playButton->setPosition(204, 850);
	playButton->setText("Play");
	playButton->setCallback
	(
		[this]()
		{
			requestStackPop();
			requestStackPush(States::Loading);
		}
	);

	auto settingsButton = std::make_shared<GUI::cButton>(*context.fonts, *context.textures);
	settingsButton->setPosition(204, 900);
	settingsButton->setText("Settings");
	settingsButton->setCallback
	(
		[this]()
		{
			requestStackPop();
			requestStackPush(States::Setting);
		}
	);

	auto exitButton = std::make_shared<GUI::cButton>(*context.fonts, *context.textures);
	exitButton->setPosition(204, 950);
	exitButton->setText("Exit");
	exitButton->setCallback
	(
		[this]()
		{
			requestStackPop();
			exit(0);
		}
	);


	mGUIContainer.pack(playButton);
	mGUIContainer.pack(settingsButton);
	mGUIContainer.pack(exitButton);

	
}

void MenuState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());

	window.draw(mBackgroundSprite);
	window.draw(mGUIContainer);
	window.draw(mVersion);
}

bool MenuState::update(sf::Time)
{
	return true;
}

bool MenuState::handleEvent(const sf::Event& event)
{
	sf::RenderWindow& window = *getContext().window;
	mGUIContainer.handleEvent(event, window);
	return false;
}