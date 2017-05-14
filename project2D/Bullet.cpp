// #include, using, etc
#include "Bullet.h"
#include "CollisionManager.h"
#include <iostream>
using namespace std;

//--------------------------------------------------------------------------------------
// Default Constructor.
//
// Param: 
//		textureUrl: Takes in a char for specifying a texture url in texture file location.
//		pos: Vector2 for the position of the object.
//		rad: float for size of the object.
//--------------------------------------------------------------------------------------
Bullet::Bullet(char* textureUrl, Vector2 pos, float rad) : Entity(textureUrl)
{
	// Create a collidable object for Bullets.
	CollisionManager* collider = CollisionManager::GetInstance();
	collider->AddObject(this);

	// Initialize rad and speed
	this->rad = rad;
	speed = 250;

	// Bind the boundingbox with the bullet rad. (for AABB collision.)
	m_Collider.m_rad = rad;

	// Set the type of object to Bullet
	this->SetType(BULLET);

	// Set the position of Bullets using a matrix3
	Matrix3 temp;
	temp.setPostionv(pos);
	localTransform = localTransform * temp;
	updateGlobalTransform();
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Bullet::~Bullet()
{
}

//--------------------------------------------------------------------------------------
// Update: A virtual function from entity to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//--------------------------------------------------------------------------------------
void Bullet::Update(float deltaTime)
{
	// Set the position and update the local and global transform.
	Matrix3 temp;
	temp.setPostionv(dir * speed * deltaTime);
	localTransform = localTransform * temp;
	updateGlobalTransform();

	// Test Collision
	CollisionManager* pCollision = CollisionManager::GetInstance();
	Entity* colliding = pCollision->TestSphereBoxCollision(this);

	// Check if the Bullet is colliding with a wall
	if (colliding != nullptr && colliding->GetType() == WALL)
	{
		// Debug message for console
		cout << "BULLET!" << endl;

		// Bounce the bullet off the wall
 		dir = pCollision->Bounce(colliding, dir, GetPosition());
	}
}

//--------------------------------------------------------------------------------------
// Draw: A virtual function from entity to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void Bullet::Draw(Renderer2D* renderer2D)
{
	// Set the color.
	renderer2D->setRenderColour(1, 1, 1, 1);

	// Draw/Render the bullet.
	renderer2D->drawCircle(GetPosition().x, GetPosition().y, rad);

	// Change color back to make sure only this object is yellow.
	renderer2D->setRenderColour(1, 1, 1, 1);
}

//--------------------------------------------------------------------------------------
// SetDir: Set the direction of the bullet.
//
// Param:
//		dir: a Vector2 for the direction of the Bullet object.
//--------------------------------------------------------------------------------------
void Bullet::SetDir(Vector2 dir)
{
	this->dir = dir;
}

