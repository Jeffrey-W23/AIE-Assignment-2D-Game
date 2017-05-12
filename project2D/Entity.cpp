#include "Entity.h"
#include "VectorCast.h"

using namespace std;

Entity::Entity(char* textureUrl)
{
	Parent = nullptr;

	m_Collider.m_TL = Vector2(-30, -30);
	m_Collider.m_BR = Vector2(30, 30);

	boundingBox.SetSize(Vector3(-60, -60, 0));

	if (textureUrl != nullptr)
	{
		char tempChar[32];
		strcpy(tempChar, "./textures/");
		strcat(tempChar, textureUrl);
		strcat(tempChar, ".png");
		texture = new Texture(tempChar);
	}
	else
	{
		texture = nullptr;
	}
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

void Entity::LocalToGlobal()
{
	localTransform = GlobalTrasform;
}

void Entity::Draw(Renderer2D* renderer2D)
{
	if (texture)
	{
		renderer2D->drawSpriteTransformed3x3(texture, GlobalTrasform);
	}

	renderer2D->drawLine(boundingBox.LowerLeft.x, boundingBox.LowerLeft.y, boundingBox.UpperRight.x, boundingBox.UpperRight.y, 10, 0);

	for (int i = 0; i < children.size(); i++)
	{
		children[i]->Draw(renderer2D);
	}
}


void Entity::SetType(Types types)
{
	this->types = types;
}

Types Entity::GetType()
{
	return types;
}