#pragma once
#include "stdafx.h"
#include "Entity.h"
#include "TextureHolder.h"
#include "DataTables.h"
#include "TextNode.h"
#include "CommandQueue.h"
#include "Projectile.h"

class Crafter : public Entity
{
public:
	enum Type
	{
		Player,
		Enemy,
		TypeCount
	};

public:
	explicit		 Crafter(Type type, TextureHolder& textures, FontHolder& fonts);
					 ~Crafter();

	virtual void	 drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void	 updateCurrent(sf::Time dt, CommandQueue& command);
	Textures::ID	 toTextureID(Crafter::Type type);

	unsigned int	 getCategory() const;
	void			 updateTexts();

	void			 fire1();

private:

	void			 createBullets(SceneNode& node, const TextureHolder& textures) const;
	void			 createProjectile(SceneNode& node, Projectile::Type type, float xOffset, float yOffset, const TextureHolder& textures) const;

private:
	Type			 mType;
	sf::Sprite		 mSprite;
	TextNode*		 mHealthDisplay;

	sf::Time		 mFireCountdown;
	bool 			 mIsFiring;

	Command 		 mFireCommand;
	Command			 mMissileCommand;
};

