#include "CreditState.h"

CreditState::CreditState(StateStack & stack, Context context) : State(stack, context), mGUIContainer()
{
	auto exitButtons = std::make_shared<GUI::cButton>(*context.fonts, *context.textures);
	exitButtons->setPosition(204, 950);
	exitButtons->setText("Back");
	exitButtons->setToggle(true);
	exitButtons->setCallback
	(
		[this]()
		{
			requestStackPop();
			requestStackPush(States::Setting);
		}
	);

	mGUIContainer.pack(exitButtons);
}

void CreditState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());

	window.draw(mGUIContainer);
}

bool CreditState::update(sf::Time dt)
{
	return true;
}

bool CreditState::handleEvent(const sf::Event & event)
{
	sf::RenderWindow& window = *getContext().window;
	mGUIContainer.handleEvent(event, window);
	return true;
}
