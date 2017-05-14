// #include, using, etc
#pragma once
#include "Entity.h"

//--------------------------------------------------------------------------------------
// Bullet object
//--------------------------------------------------------------------------------------
class Bullet : public Entity
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//
	// Param: 
	//		textureUrl: Takes in a char for specifying a texture url in texture file location.
	//		pos: Vector2 for the position of the object.
	//		rad: float for size of the object.
	//--------------------------------------------------------------------------------------
	Bullet(char* textureUrl, Vector2 pos, float rad);
	
	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Bullet();

	//--------------------------------------------------------------------------------------
	// Update: A virtual function from entity to update objects.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//--------------------------------------------------------------------------------------
	void Update(float deltaTime);

	//--------------------------------------------------------------------------------------
	// Draw: A virtual function from entity to render (or "draw") objects to the screen.
	//
	// Param:
	//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
	//--------------------------------------------------------------------------------------
	void Draw(Renderer2D* renderer2D);

	//--------------------------------------------------------------------------------------
	// SetDir: Set the direction of the bullet.
	//
	// Param:
	//		dir: a Vector2 for the direction of the Bullet object.
	//--------------------------------------------------------------------------------------
	void SetDir(Vector2 dir);

private:

	//--------------------------------------------------------------------------------------
	// A float for what the speed should be.
	//--------------------------------------------------------------------------------------
	float speed;

	//--------------------------------------------------------------------------------------
	// A float for the radius of the Bullet.
	//--------------------------------------------------------------------------------------
	float rad;

	//--------------------------------------------------------------------------------------
	// A Vector2 for the direction of the bullet.
	//--------------------------------------------------------------------------------------
	Vector2 dir;
};

