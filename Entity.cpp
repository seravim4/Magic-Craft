#include "Entity.h"


Entity::Entity(int hitpoints, int mana) : mHitpoints(hitpoints), mMana(mana)
{
}

int Entity::getHitpoints() const
{
	return mHitpoints;
}

int Entity::getMana() const
{
	return mMana;
}

void Entity::destroy()
{
	mHitpoints = 0;
}

bool Entity::isDestroyed() const
{
	return mHitpoints <= 0;
}

void Entity::updateCurrent(sf::Time dt, CommandQueue& command)
{
	
}
