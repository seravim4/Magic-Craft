#include "DataTables.h"
#include "Crafter.h"
#include "Projectile.h"

using namespace std::placeholders;

std::vector<CrafterData> initCrafterData()
{
	std::vector<CrafterData> data(Crafter::TypeCount);

	data[Crafter::Player].hitpoints = 100;
	data[Crafter::Player].mana		= 100;
	data[Crafter::Player].texture	= Textures::Player;

	data[Crafter::Enemy].hitpoints  = 100;
	data[Crafter::Enemy].mana		= 100;
	data[Crafter::Enemy].texture	= Textures::Enemy;

	return data;
}

std::vector<ProjectileData> initProjectileData()
{
	std::vector<ProjectileData> data(Projectile::TypeCount);

	data[Projectile::Fire1].damage = 10;
	data[Projectile::Fire1].speed = 300.f;
	data[Projectile::Fire1].texture = Textures::ActivePoint;

	return data;
}
