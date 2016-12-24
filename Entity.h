#pragma once
#include "stdafx.h"
#include "SceneNode.h"
#include "CommandQueue.h"

class Entity : public SceneNode
{
public:

	explicit		Entity(int hitpoints, int mana);

	int				getHitpoints() const;
	int				getMana()	   const;
	void			destroy();
	virtual bool	isDestroyed()  const;

protected:

	virtual void	updateCurrent(sf::Time dt, CommandQueue& command);

private:

	int				mHitpoints;
	int				mMana;
};

