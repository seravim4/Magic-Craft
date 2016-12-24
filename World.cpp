#include "World.h"


World::World(sf::RenderWindow & window) : 
	mWindow(window),
	mWorldView(window.getDefaultView()),
	mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f),
	mSpawnPosition(mWorldView.getSize().x / 2.f,
					mWorldBounds.height - mWorldView.getSize().y),
	mPlayer(nullptr)
{
	loadTextures();
	buildScene();

	mWorldView.setCenter(mSpawnPosition);
}

World::~World()
{

}

void World::update(sf::Time dt)
{
	while (!mCommandQueue.isEmpty())
		mSceneGraph.onCommand(mCommandQueue.pop(), dt);

	mSceneGraph.update(dt, mCommandQueue);
}

void World::draw()
{
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);
	mWindow.draw(PlayerHp);
}

bool World::handleEvent(const sf::Event & event)
{
	return true;
}

void World::loadTextures()
{
	mTextures.load(Textures::Player, "image/player.png");
	mTextures.load(Textures::Location, "image/Location.png");
	mTextures.load(Textures::Enemy, "image/enemy.png");
	mTextures.load(Textures::Bar, "image/bar.png");
}

void World::buildScene()
{
	for (std::size_t i = 0; i < LayerCount; i++)
	{
		SceneNode::Ptr layer(new SceneNode());
		mSceneLayers[i] = layer.get();

		mSceneGraph.attachChild(std::move(layer));
	}

	sf::Texture& texture = mTextures.get(Textures::Location);
	sf::Texture& barTexture = mTextures.get(Textures::Bar);
	sf::IntRect textureRect(mWorldBounds);
	texture.setRepeated(true);
	barTexture.setRepeated(true);

	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture));
	backgroundSprite->setPosition(850, 330);
	mSceneLayers[Background]->attachChild(std::move(backgroundSprite));

	std::unique_ptr<SpriteNode> playerBar(new SpriteNode(barTexture));
	playerBar->setPosition(850, 1020);
	mSceneLayers[Interface]->attachChild(std::move(playerBar));

	std::unique_ptr<Crafter> lPlayer(new Crafter(Crafter::Player, mTextures, mFonts));
	mPlayer = lPlayer.get();
	mPlayer->setPosition(mSpawnPosition);
	mSceneLayers[Entitys]->attachChild(std::move(lPlayer));

	std::unique_ptr<Crafter> rightEnemy(new Crafter(Crafter::Enemy, mTextures, mFonts));
	rightEnemy->setPosition(600.f, 0.f);
	mPlayer->attachChild(std::move(rightEnemy));
}
