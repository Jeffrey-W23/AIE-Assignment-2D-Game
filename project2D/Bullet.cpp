#include "Bullet.h"
#include "CollisionManager.h"
#include <iostream>
using namespace std;

Bullet::Bullet(char* textureUrl, Vector2 pos, float rad) : Entity(textureUrl)
{
	CollisionManager* collider = CollisionManager::GetInstance();
	collider->AddObject(this);

	this->rad = rad;

	m_Collider.m_rad = rad;

	this->SetType(BULLET);

	Matrix3 temp;
	temp.setPostionv(pos);
	localTransform = localTransform * temp;
	updateGlobalTransform();

	speed = 250;

}

Bullet::~Bullet()
{
}

void Bullet::SetDir(Vector2 dir)
{
	this->dir = dir;
}

void Bullet::Draw(Renderer2D* renderer2D)
{
	renderer2D->setRenderColour(1, 1, 1, 1);
	renderer2D->drawCircle(GetPosition().x, GetPosition().y, rad);
	renderer2D->setRenderColour(1, 1, 1, 1);
}

void Bullet::Update(float deltaTime)
{
	Matrix3 temp;
	temp.setPostionv(dir * speed * deltaTime);
	localTransform = localTransform * temp;
	updateGlobalTransform();

	// Test Collision
	CollisionManager* pCollision = CollisionManager::GetInstance();

	Entity* colliding = pCollision->TestSphereBoxCollision(this);

	if (colliding != nullptr && colliding->GetType() == WALL)
	{

		//colliding->GetCollider
		cout << "BULLET!" << endl;

 		dir = pCollision->Bounce(colliding, dir, GetPosition());
	}
}
