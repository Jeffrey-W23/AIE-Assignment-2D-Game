#include "Wall.h"
#include "VectorCast.h"

Wall::Wall(char* textureUrl, Vector2 pos, Vector2 size) : Entity(textureUrl)
{
	CollisionManager* collider = CollisionManager::GetInstance();
	collider->AddObject(this);

	this->size = size;

	Matrix3 temp;
	temp.setPostionv(pos);
	localTransform = localTransform * temp;
	updateGlobalTransform();

	boundingBox.MoveTo(CastTo<Vector3>(GetPosition()));
	//boundingBox.RotateBy(rottemp);

	m_Collider.m_TL = Vector2(-size.x * 0.5, -size.y * 0.5);
	m_Collider.m_BR = Vector2(size.x * 0.5, size.y * 0.5);

	this->SetType(WALL);
}

Wall::~Wall()
{
}

void Wall::Draw(Renderer2D* renderer2D)
{
	renderer2D->setRenderColour(1, 1, 0, 1);
	renderer2D->drawBox(GetPosition().x, GetPosition().y, size.x, size.y);
	renderer2D->setRenderColour(1, 1, 1, 1);

	renderer2D->drawLine(boundingBox.LowerLeft.x, boundingBox.LowerLeft.y, boundingBox.UpperRight.x, boundingBox.UpperRight.y, 10, 0);
}

void Wall::Update(float deltaTime)
{
}