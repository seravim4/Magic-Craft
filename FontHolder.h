#pragma once
#include "stdafx.h"

namespace Fonts
{
	enum ID
	{
		Main
	};
}

class FontHolder
{
private:

	std::map<Fonts::ID, std::unique_ptr<sf::Font>> mFontMap;

public:

	void				load(Fonts::ID id, const std::string& filename);
	sf::Font&			get(Fonts::ID id);
	const sf::Font&		get(Fonts::ID id) const;
};

