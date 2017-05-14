// #include, using, etc
#pragma once
#include "Entity.h"
#include "Renderer2D.h"
#include "turret.h"

//--------------------------------------------------------------------------------------
// Player object. Inheritance from Entity.
//--------------------------------------------------------------------------------------
class Player : public Entity
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//
	// Param: 
	//		textureUrl: Takes in a char for specifying a texture url in texture file location.
	//--------------------------------------------------------------------------------------
	Player(char* textureUrl);

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Player();

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
	// A float rotSpeed for the speed of rotation. 
	//--------------------------------------------------------------------------------------
	float rotSpeed;

	//--------------------------------------------------------------------------------------
	// A pointer to Turret.
	//--------------------------------------------------------------------------------------
	turret* Turret;
};