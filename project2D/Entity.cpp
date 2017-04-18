#include "Entity.h"

Entity::Entity()
{
	Parent = nullptr;

	m_Collider.m_TL = Vector2(-30, -30);
	m_Collider.m_BR = Vector2(30, 30);
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

void Entity::updateGlobalTransform()
{
	if (Parent != nullptr)
	{
		GlobalTrasform = Parent->GlobalTrasform * localTransform;
	}
	else
	{
		GlobalTrasform = localTransform;
	}
	
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->updateGlobalTransform();
	}
}

Collider& Entity::GetCollider()
{
	return m_Collider;
}

Vector2 Entity::GetPosition()
{
	Vector2 pos;

	pos.x = GlobalTrasform.m[6];
	pos.y = GlobalTrasform.m[7];

	return pos;
}