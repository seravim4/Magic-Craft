#pragma once
#include "State.h"
#include "stdafx.h"
#include "ParallelTask.h"

class LoadingState : public State
{
public:
	
					LoadingState(StateStack& stack, Context context);

	virtual void	draw();
	virtual bool	update(sf::Time dt);
	virtual bool	handleEvent(const sf::Event& event);

	void			setComplection(float percent);

private:

	sf::Text				mLoadingText;
	sf::Sprite				mBackgroundSprite;
	sf::RectangleShape		mProgressBarBackground;
	sf::RectangleShape		mProgressBar;

	ParallelTask			mLoadingTask;
	sf::Clock				mElapsedTime;
};

