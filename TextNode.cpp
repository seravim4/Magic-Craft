#include "TextNode.h"

TextNode::TextNode(const FontHolder & fonts, const std::string & text)
{
	mText.setFont(fonts.get(Fonts::Main));
	mText.setCharacterSize(20);
	setString(text);
}

void TextNode::setString(const std::string & text)
{
	mText.setString(text);
	sf::FloatRect bounds = mText.getLocalBounds();
	mText.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}

void TextNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(mText, states);
}
