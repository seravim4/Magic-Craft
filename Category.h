#pragma once

namespace Category
{
	enum Type
	{
		None = 0,
		SceneLayer = 1       << 0,
		PlayerCraft = 1      << 1,
		AlliedCraft = 1      << 2,
		EnemyCraft = 1       << 3,
		AlliedProjectile = 1 << 4,
		EnemyProjectile = 1  << 5,

		Craft = PlayerCraft | EnemyCraft | AlliedCraft,
		Projectile = EnemyProjectile | AlliedProjectile
	};
}