#pragma once
#include "State.h"
#include "StateStack.h"
#include "stdafx.h"
#include "StateIdentifier.h"

class TitleState : public State
{
public:
							TitleState(StateStack& stack, State::Context context);

	virtual void			draw();
	virtual bool			update(sf::Time dt);
	virtual bool			handleEvent(const sf::Event& event);

private:

	sf::Sprite				mBackgroundSprite;
	sf::Text				mText;

	bool					mShowText;
	sf::Time				mTextEffectTime;
};

