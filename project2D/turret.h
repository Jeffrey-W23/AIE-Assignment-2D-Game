// #include, using, etc
#pragma once
#include "Entity.h"
#include "Antenna.h"
#include "Bullet.h"

//--------------------------------------------------------------------------------------
// Turret object. Inheritance from Entity.
//--------------------------------------------------------------------------------------
class turret : public Entity
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//
	// Param: 
	//		textureUrl: Takes in a char for specifying a texture url in texture file location.
	//--------------------------------------------------------------------------------------
	turret(char* textureUrl);
	
	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~turret();

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
	// A float for rotSpeed. Used fore the speed that the object should rotate.
	//--------------------------------------------------------------------------------------
	float rotSpeed;
	
	//--------------------------------------------------------------------------------------
	// A pointer to Antenna.
	//--------------------------------------------------------------------------------------
	Antenna* antenna;
	
	//--------------------------------------------------------------------------------------
	// A pointer to an array of 15 Bullets.
	//--------------------------------------------------------------------------------------
	Bullet* bullets[15];

	//--------------------------------------------------------------------------------------
	// A int for bulletCount. Used to keep track of how many bullets have been fired.
	//--------------------------------------------------------------------------------------
	int bulletCount;
};