#pragma once
#include "stdafx.h"
#include "TextureHolder.h"
#include "SceneNode.h"
#include "Crafter.h"
#include "SpriteNode.h"
#include "Command.h"
#include "CommandQueue.h"
#include "TextNode.h"

class World : private sf::NonCopyable
{
public:

	explicit				 World(sf::RenderWindow& window);
		   					 ~World();

	void					 update(sf::Time dt);
	void					 draw();
	bool					 handleEvent(const sf::Event& event);

private:

	void					 loadTextures();
	void					 buildScene();

private:

	enum Layer
	{
		Background,
		Entitys,
		Interface,
		LayerCount
	};

private:

	sf::RenderWindow&						mWindow;
	sf::View								mWorldView;
	TextureHolder							mTextures;
	FontHolder								mFonts;
	SceneNode								mSceneGraph;
	std::array<SceneNode*, LayerCount>		mSceneLayers;
	sf::Text								PlayerHp;

	sf::FloatRect							mWorldBounds;
	Crafter*								mPlayer;

	sf::Vector2f							mSpawnPosition;
	CommandQueue							mCommandQueue;
};

