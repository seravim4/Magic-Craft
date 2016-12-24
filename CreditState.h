#pragma once
#include "Foreach.h"
#include "TextureHolder.h"
#include "FontHolder.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>

#include "State.h"
#include "StateIdentifier.h" 
#include "StateStack.h"
#include "cButton.h"
#include "Container.h"



class CreditState : State
{
public:
	
							CreditState(StateStack& stack, Context context);

	virtual void			draw();
	virtual bool			update(sf::Time dt);
	virtual bool			handleEvent(const sf::Event& event);

private:

	GUI::Container			mGUIContainer;
};

