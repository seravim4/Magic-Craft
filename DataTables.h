#pragma once

#include "FontHolder.h"
#include "TextureHolder.h"
#include <SFML\System\Time.hpp>
#include <SFML\Graphics\Color.hpp>
#include <vector>
#include <functional>

class Crafter;

struct CrafterData
{
	int			 hitpoints;
	int			 mana;
	Textures::ID texture;
};

struct ProjectileData
{
	int								damage;
	float							speed;
	Textures::ID					texture;
};

std::vector<CrafterData>		initCrafterData();
std::vector<ProjectileData>		initProjectileData();