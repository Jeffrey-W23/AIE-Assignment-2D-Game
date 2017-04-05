#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::setParent(Entity* parent)
{
	Parent = parent;
}

void Entity::setChild(Entity* child)
{
	children.push_back(child);
}