#pragma once
#include "Component.h"
#include "stdafx.h"
#include "FontHolder.h"
#include "TextureHolder.h"

namespace GUI
{
	class Points : public Component
	{
	public:

		typedef std::shared_ptr<Points>	Ptr;
		typedef std::function<void()>	Callback;
		bool							foo;

	public:

		Points(const FontHolder& fonts, const TextureHolder& textures);

		void				setCallback(Callback callback);
		void				setText(const std::string& text);
		void				setToggle(bool flag);

		virtual bool		isSelectable() const;
		virtual void		select();
		virtual void		deselect();

		virtual void		activate();
		virtual void		deactivate();
		virtual void		handleEvent(const sf::Event& event, sf::RenderWindow& window);
		virtual void		update(const sf::Event& event, sf::Vector2f pos);

		bool				mIsSelection;

	private:

		virtual void		draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:

		Callback			mCallback;
		const sf::Texture&	mNormalTexture;
		const sf::Texture&	mSelectedTexture;
		const sf::Texture&	mPressedTexture;
		sf::Sprite			mSprite;
		sf::Text			mText;
		bool				mIsToggle;
	};
}
