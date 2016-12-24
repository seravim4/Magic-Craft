#pragma once
#include "State.h"
#include "Container.h"
#include "cButton.h"
#include "Label.h"
#include "Player.h"

#include "stdafx.h"


class SettingsState : public State
{
public:
	
							SettingsState(StateStack& stack, Context context);
	virtual void			draw();
	virtual bool			update(sf::Time dt);
	virtual bool			handleEvent(const sf::Event& event);

private:

	void					updateLabels();
	void					addButtonLabel(Player::Action action, float y, const std::string& text, Context context);

private:

	sf::Sprite							mBackgroundSprite;
	sf::Text							mWarningMessage;
	GUI::Container						mGUIContainer;
	bool								mShowText;
	bool								iskeyPressed;
	sf::Time							mTextEffectTime;

private:

	std::array<GUI::cButton::Ptr, Player::ActionCount>	mBindingButtons;
	std::array<GUI::Label::Ptr, Player::ActionCount> 	mBindingLabels;
};

