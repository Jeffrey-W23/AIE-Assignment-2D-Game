#include "Wall.h"

Wall::Wall(char* textureUrl, Vector2 pos, Vector2 size) : Entity(textureUrl)
{
	CollisionManager* collider = CollisionManager::GetInstance();
	collider->AddObject(this);

	this->pos = pos;
	this->size = size;

	m_Collider.m_TL = Vector2(-size.x * 0.5, -size.y * 0.5);
	m_Collider.m_BR = Vector2(size.x * 0.5, size.y * 0.5);
}

Wall::~Wall()
{
}

void Wall::Draw(Renderer2D* renderer2D)
{
	renderer2D->setRenderColour(1, 1, 0, 1);
	renderer2D->drawSprite(nullptr, pos.x, pos.y, size.x, size.y);
	renderer2D->setRenderColour(1, 1, 1, 1);
}

void Wall::Update(float deltaTime)
{
}