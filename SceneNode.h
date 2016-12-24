#pragma once
#include "stdafx.h"
#include "Category.h"
#include "CommandQueue.h"

struct Command;

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable 
{
public:

	typedef std::unique_ptr<SceneNode> Ptr;

public:

						SceneNode();

	void				attachChild(Ptr child);
	Ptr					detachChild(const SceneNode& node);
	void				update(sf::Time dt, CommandQueue& command);
	void				onCommand(const Command& command, sf::Time dt);

	sf::Vector2f		getWorldPosition() const;
	sf::Transform		getWorldTransform() const;
	unsigned int		getCategory() const;

	virtual bool		isDestroyed() const;

private:

	std::vector<Ptr>	mChildren;
	SceneNode*			mParent;

private:

	virtual void		draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void		drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void		updateCurrent(sf::Time dt, CommandQueue& command);

	void				updateChildren(sf::Time dt, CommandQueue& command);
	void				drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;


};

