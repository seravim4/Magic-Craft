#pragma once
#include "stdafx.h"

namespace Textures
{
	enum ID
	{
		Lanscape, 
		Player, 
		Enemy,
		Location,
		Grid,
		Mouse,
		TitleScreen,
		ButtonNormal,
		ButtonSelected,
		ButtonPressed,
		Point,
		BackgroundPoint,
		SelectPoint,
		ActivePoint,
		Bar
	};
}

class TextureHolder
{
private:
	std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;

public:
	void				load(Textures::ID id, const std::string& filename);
	sf::Texture&		get(Textures::ID id);
	const sf::Texture&  get(Textures::ID id) const;
};


