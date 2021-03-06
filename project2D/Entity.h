//#include, using etc
#pragma once
#include "Matrix3.h"
#include "Vector2.h"
#include <vector>
#include "Collider.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "rect.h"
using namespace std;
using namespace aie;

// Enums for each type a entity can be
enum Types
{
	BULLET,
	WALL,
	PLAYER,
	ANTENNA
};

//--------------------------------------------------------------------------------------
// Entity object
//--------------------------------------------------------------------------------------
class Entity
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//
	// Param: 
	//		textureUrl: Takes in a char for specifying a texture url in texture file location.
	//--------------------------------------------------------------------------------------
	Entity(char* textureUrl);
	
	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~Entity();

	//--------------------------------------------------------------------------------------
	// setParent: Set the parent of the entity.
	//
	// Param:
	//		sParent: An entity for the parent object.
	//--------------------------------------------------------------------------------------
	void setParent(Entity* sParent);

	//--------------------------------------------------------------------------------------
	// setChild: Set the child of the entity.
	//
	// Param:
	//		sChild: An entity for the child object.
	//--------------------------------------------------------------------------------------
	void setChild(Entity* sChild);

	//--------------------------------------------------------------------------------------
	// updateGlobalTransform: Update the Global Transform.
	//--------------------------------------------------------------------------------------
	void updateGlobalTransform();

	//--------------------------------------------------------------------------------------
	// GetCollider
	//
	// Return:
	//		Collider: Return Collider
	//--------------------------------------------------------------------------------------
	Collider& GetCollider();

	//--------------------------------------------------------------------------------------
	// GetPosition: Get the position of the entity.
	//--------------------------------------------------------------------------------------
	Vector2 GetPosition();

	//--------------------------------------------------------------------------------------
	// SetPosition: Set the position of the entity.
	//
	// Param:
	//		x: a float for the x of entity.
	//		y: a float for the y of enity.
	//--------------------------------------------------------------------------------------
	void SetPosition(float x, float y);

	//--------------------------------------------------------------------------------------
	// SetType: Set what type the entity is.
	//
	// Param:
	//		types: a Type enum value.
	//--------------------------------------------------------------------------------------
	void SetType(Types types);

	//--------------------------------------------------------------------------------------
	// Update: Get the Entity type.
	//
	// Return:
	//		Types: Returns the type for the entity.
	//--------------------------------------------------------------------------------------
	Types GetType();

	//--------------------------------------------------------------------------------------
	// LocalToGlobal: Change a localtransform to a globaltransform.
	//--------------------------------------------------------------------------------------
	void LocalToGlobal();

	//--------------------------------------------------------------------------------------
	// Update: A virtual function to update objects.
	//
	// Param:
	//		deltaTime: Pass in deltaTime. A number that updates per second.
	//--------------------------------------------------------------------------------------
	virtual void Update(float deltaTime);

	//--------------------------------------------------------------------------------------
	// Draw: A virtual function to render (or "draw") objects to the screen.
	//
	// Param:
	//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
	//--------------------------------------------------------------------------------------
	virtual void Draw(Renderer2D* renderer2D);

	//--------------------------------------------------------------------------------------
	// A rect used as the bounding box for all entites
	//--------------------------------------------------------------------------------------
	rect boundingBox;

protected:

	//--------------------------------------------------------------------------------------
	// A Entity pointer for parent
	//--------------------------------------------------------------------------------------
	Entity* Parent;

	//--------------------------------------------------------------------------------------
	// A Dynamic array of Entity pointers
	//--------------------------------------------------------------------------------------
	vector<Entity*> children;

	//--------------------------------------------------------------------------------------
	// A Matrix3 for the local and global transforms.
	//--------------------------------------------------------------------------------------
	Matrix3 localTransform;
	Matrix3 GlobalTrasform;

	//--------------------------------------------------------------------------------------
	// An instance of the Collider
	//--------------------------------------------------------------------------------------
	Collider m_Collider;

	//--------------------------------------------------------------------------------------
	// A pointer to texture.
	//--------------------------------------------------------------------------------------
	Texture* texture;

	//--------------------------------------------------------------------------------------
	// An instance of Type. What type is the object
	//--------------------------------------------------------------------------------------
	Types types;
};