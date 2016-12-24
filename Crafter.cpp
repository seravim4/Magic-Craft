#include "Crafter.h"
#include "TextNode.h"
#include "Projectile.h"
#include <cmath>

namespace
{
	const std::vector<CrafterData> Table = initCrafterData();
}

Crafter::Crafter(Type type, TextureHolder& textures, FontHolder& fonts) :
	mType(type),
	mSprite(textures.get(Table[type].texture)),
	Entity(Table[type].hitpoints, Table[type].mana),
	mHealthDisplay(nullptr),
	mFireCountdown(sf::Time::Zero),
	mIsFiring(false),
	mFireCommand()
{
	sf::FloatRect bounds = mSprite.getLocalBounds();
	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);

	mFireCommand.category = Category::SceneLayer;
	mFireCommand.action = [this, &textures](SceneNode& node, sf::Time)
	{
		createBullets(node, textures);
	};

	mMissileCommand.category = Category::SceneLayer;
	mMissileCommand.action = [this, &textures](SceneNode& node, sf::Time)
	{
		createProjectile(node, Projectile::Fire1, 0.f, 0.5f, textures);
	};

	//alpha 0.3
	updateTexts();
}

Crafter::~Crafter()
{

}

void Crafter::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

void Crafter::updateCurrent(sf::Time dt, CommandQueue & command)
{
	if (mType == Type::Enemy)
	{
		fire1();
	}

	if (isDestroyed())
	{
		return;
	}

	Entity::updateCurrent(dt, command);

	updateTexts();
}

Textures::ID Crafter::toTextureID(Crafter::Type type)
{
	switch (type)
	{
	case Crafter::Player:
		return Textures::Player;
		break;
	case Crafter::Enemy:
		return Textures::Enemy;
		break;
	}
}

unsigned int Crafter::getCategory() const
{
	switch (mType)
	{
	case Crafter::Player:
		return Category::PlayerCraft;
		break;
	case Crafter::Enemy:
		return Category::EnemyCraft;
		break;
	default:
		break;
	}
}

//alpha 0.3
void Crafter::updateTexts()
{
}
//alpha 0.1, this is damage abilites
void Crafter::fire1()
{
	if (Table[mType].mana != 0)
		mIsFiring = true;
}

void Crafter::createBullets(SceneNode & node, const TextureHolder & textures) const
{
	Projectile::Type type = mType == Crafter::Player ? Projectile::Fire1 : Projectile::EnemyFire1;

	createProjectile(node, type, 0.0f, 0.5f, textures);
}

void Crafter::createProjectile(SceneNode & node, Projectile::Type type, float xOffset, float yOffset, const TextureHolder & textures) const
{
	std::unique_ptr<Projectile> projectile(new Projectile(type, textures));

	sf::Vector2f offset(xOffset * mSprite.getGlobalBounds().width, yOffset * mSprite.getGlobalBounds().height);
	sf::Vector2f velocity(0, projectile->getMaxSpeed());

	float sign = mType == Crafter::Player ? -1.f : +1.f;
	projectile->setPosition(getWorldPosition() + offset * sign);
	node.attachChild(std::move(projectile));
}


