// #include, using, etc
#include "Map.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Map::Map()
{
	// Create each wall
	wall1 = new Wall(nullptr, Vector2(0, -100), Vector2(50, 50));
	wall2 = new Wall(nullptr, Vector2(0, 400), Vector2(50, 50));
	wall3 = new Wall(nullptr, Vector2(-487, 150), Vector2(50, 50));
	wall4 = new Wall(nullptr, Vector2(488, 150), Vector2(50, 50));
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Map::~Map()
{
	delete wall1;
	delete wall2;
	delete wall3;
	delete wall4;
}

//--------------------------------------------------------------------------------------
// Update: A virtual function from entity to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//--------------------------------------------------------------------------------------
void Map::Update(float deltaTime)
{
}

//--------------------------------------------------------------------------------------
// Draw: A virtual function from entity to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void Map::Draw(Renderer2D* renderer2D)
{
	wall1->Draw(renderer2D);
	wall2->Draw(renderer2D);
	wall3->Draw(renderer2D);
	wall4->Draw(renderer2D);
}