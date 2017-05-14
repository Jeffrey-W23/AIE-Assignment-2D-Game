// #include, using, etc
#pragma once
#include "Entity.h"

//--------------------------------------------------------------------------------------
// Wall object. Inheritance from Entity.
//--------------------------------------------------------------------------------------
class Wall : public Entity
{
public:
	
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//
	// Param: 
	//		textureUrl: Takes in a char for specifying a texture url in texture file location.
	//		pos: Vector2 for the position of the object.
	//		size: Vector2 for size of the object.
	//--------------------------------------------------------------------------------------
	Wall(char* textureUrl, Vector2 pos, Vector2 size);
	
	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Wall();

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
	// A Vector2 size. Used for the size of each wall.
	//--------------------------------------------------------------------------------------
	Vector2 size;
};