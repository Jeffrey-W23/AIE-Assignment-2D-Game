// #include, using, etc
#include "Wall.h"
#include "VectorCast.h"
#include "CollisionManager.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//
// Param: 
//		textureUrl: Takes in a char for specifying a texture url in texture file location.
//		pos: Vector2 for the position of the object.
//		size: Vector2 for size of the object.
//--------------------------------------------------------------------------------------
Wall::Wall(char* textureUrl, Vector2 pos, Vector2 size) : Entity(textureUrl)
{
	// Create a collidable object for walls.
	CollisionManager* collider = CollisionManager::GetInstance();
	collider->AddObject(this);

	this->size = size;

	// Set the position of walls using a matrix3
	Matrix3 temp;
	temp.setPostionv(pos);
	localTransform = localTransform * temp;
	updateGlobalTransform();

	// Bind the boundingbox with the walls. (for SAT collision.)
	boundingBox.MoveTo(CastTo<Vector3>(GetPosition()));

	// Bind the boundingbox with the walls. (for AABB collision.)
	m_Collider.m_TL = Vector2(-size.x * 0.5f, -size.y * 0.5f);
	m_Collider.m_BR = Vector2(size.x * 0.5f, size.y * 0.5f);

	// Set the type of object to wall
	this->SetType(WALL);
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Wall::~Wall()
{
}

//--------------------------------------------------------------------------------------
// Update: A virtual function from entity to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//--------------------------------------------------------------------------------------
void Wall::Update(float deltaTime)
{
}

//--------------------------------------------------------------------------------------
// Draw: A virtual function from entity to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void Wall::Draw(Renderer2D* renderer2D)
{
	// Set the color.
	renderer2D->setRenderColour(1, 1, 0, 1);
	
	// Draw/Render the wall to screen.
	renderer2D->drawBox(GetPosition().x, GetPosition().y, size.x, size.y);
	
	// Change color back to make sure only this object is yellow.
	renderer2D->setRenderColour(1, 1, 1, 1);

	// Draw the bounding box for the Walls.
	renderer2D->drawLine(boundingBox.LowerLeft.x, boundingBox.LowerLeft.y, boundingBox.UpperRight.x, boundingBox.UpperRight.y, 10, 0);
}