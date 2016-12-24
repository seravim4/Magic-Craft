#include "FontHolder.h"

void FontHolder::load(Fonts::ID id, const std::string & filename)
{
	std::unique_ptr<sf::Font> font(new sf::Font());
	if (!font->loadFromFile(filename))
		throw std::runtime_error("FontHolder::load - Failed to load " + filename);

	auto inserted = mFontMap.insert(std::make_pair(id, std::move(font)));
	assert(inserted.second);
}

sf::Font & FontHolder::get(Fonts::ID id)
{
	auto found = mFontMap.find(id);
	return *found->second;
}

const sf::Font & FontHolder::get(Fonts::ID id) const
{
	auto found = mFontMap.find(id);
	return *found->second;
}
