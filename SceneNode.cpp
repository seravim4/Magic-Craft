#include "SceneNode.h"
#include "Command.h"


SceneNode::SceneNode()
{

}

void SceneNode::attachChild(Ptr child)
{
	child->mParent = this;
	mChildren.push_back(std::move(child));
}

void SceneNode::onCommand(const Command & command, sf::Time dt)
{
	if (command.category & getCategory())
		command.action(*this, dt);

	FOREACH(Ptr& child, mChildren)
		child->onCommand(command, dt);
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode & node)
{
	auto found = std::find_if(mChildren.begin(), mChildren.end(),
		[&](Ptr& p) -> bool { return p.get() == &node; });

	assert(found != mChildren.end());

	Ptr result = std::move(*found);
	result->mParent = nullptr;
	mChildren.erase(found);
	return result;
}

void SceneNode::update(sf::Time dt, CommandQueue& command)
{
	updateCurrent(dt, command);
	updateChildren(dt, command);
}

sf::Vector2f SceneNode::getWorldPosition() const
{
	return getWorldTransform() * sf::Vector2f();
}

sf::Transform SceneNode::getWorldTransform() const
{
	sf::Transform transform = sf::Transform::Identity;
	for (const SceneNode* node = this; node != nullptr; node = node->mParent)
		transform = node->getTransform() * transform;

	return transform;
}

unsigned int SceneNode::getCategory() const
{
	return Category::SceneLayer;
}

bool SceneNode::isDestroyed() const
{
	return false;
}

void SceneNode::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	drawCurrent(target, states);
	drawChildren(target, states);
}

void SceneNode::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const
{

}

void SceneNode::updateCurrent(sf::Time dt, CommandQueue& command)
{

}

void SceneNode::updateChildren(sf::Time dt, CommandQueue& command)
{
	FOREACH(Ptr& child, mChildren)
		child->update(dt, command);
}

void SceneNode::drawChildren(sf::RenderTarget & target, sf::RenderStates states) const
{
	FOREACH(const Ptr& child, mChildren)
	{
		child->draw(target, states);
	}
}


