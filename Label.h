#pragma once
#include "FontHolder.h"
#include "TextureHolder.h"
#include "stdafx.h"
#include "Container.h"

namespace GUI
{

	class Label : public Component
	{
	public:
		typedef std::shared_ptr<Label> Ptr;


	public:
		Label(const std::string& text, const FontHolder& fonts);

		virtual bool		isSelectable() const;
		void				setText(const std::string& text);

		virtual void		handleEvent(const sf::Event& event, sf::RenderWindow& window);


	private:
		void				draw(sf::RenderTarget& target, sf::RenderStates states) const;


	public:
		sf::Text			mText;
	};

}