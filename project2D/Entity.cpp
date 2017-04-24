#include "Entity.h"

Entity::Entity(char textureUrl[32])
{
	Parent = nullptr;

	m_Collider.m_TL = Vector2(-30, -30);
	m_Collider.m_BR = Vector2(30, 30);

	char tempChar[32];
	strcpy(tempChar, "./textures/");
	strcat(tempChar, textureUrl);
	strcat(tempChar, ".png");

	texture = new Texture(tempChar);
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

void Entity::SetPosition(float x, float y)
{
	localTransform.m[6] = x;
	localTransform.m[7] = y;

	updateGlobalTransform();
}

void Entity::Update(float deltaTime)
{

}

void Entity::Draw(Renderer2D* renderer2D)
{
	renderer2D->drawSpriteTransformed3x3(texture, GlobalTrasform);
}