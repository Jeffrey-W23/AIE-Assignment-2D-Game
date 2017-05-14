//#include, using etc
#include "Entity.h"
#include "VectorCast.h"
using namespace std;

//--------------------------------------------------------------------------------------
// Default Constructor.
//
// Param: 
//		textureUrl: Takes in a char for specifying a texture url in texture file location.
//--------------------------------------------------------------------------------------
Entity::Entity(char* textureUrl)
{
	// initialize Parent to null
	Parent = nullptr;

	// Bind the boundingbox with Entity. (for AABB collision.)
	m_Collider.m_TL = Vector2(-30, -30);
	m_Collider.m_BR = Vector2(30, 30);

	// Set the size of the boundingbox
	boundingBox.SetSize(Vector3(-60, -60, 0));

	// if a textureUrl isnt given set it to null 
	if (textureUrl != nullptr)
	{
		// Create the url for the texture of the entity.
		char tempChar[32];
		strcpy(tempChar, "./textures/");
		strcat(tempChar, textureUrl);
		strcat(tempChar, ".png");
		texture = new Texture(tempChar);
	}
	else
	{
		texture = nullptr;
	}
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Entity::~Entity()
{
	delete texture;
}

//--------------------------------------------------------------------------------------
// setParent: Set the parent of the entity.
//
// Param:
//		sParent: An entity for the parent object.
//--------------------------------------------------------------------------------------
void Entity::setParent(Entity* parent)
{
	Parent = parent;
}

//--------------------------------------------------------------------------------------
// setChild: Set the child of the entity.
//
// Param:
//		sChild: An entity for the child object.
//--------------------------------------------------------------------------------------
void Entity::setChild(Entity* child)
{
	children.push_back(child);
}

//--------------------------------------------------------------------------------------
// updateGlobalTransform: Update the Global Transform.
//--------------------------------------------------------------------------------------
void Entity::updateGlobalTransform()
{
	if (Parent != nullptr)
	{
		GlobalTrasform = Parent->GlobalTrasform * localTransform;
	}
	else
	{
		GlobalTrasform = localTransform;
	}
	
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->updateGlobalTransform();
	}
}

//--------------------------------------------------------------------------------------
// GetCollider
//
// Return:
//		Collider: Return Collider
//--------------------------------------------------------------------------------------
Collider& Entity::GetCollider()
{
	return m_Collider;
}

//--------------------------------------------------------------------------------------
// GetPosition: Get the position of the entity.
//--------------------------------------------------------------------------------------
Vector2 Entity::GetPosition()
{
	Vector2 pos;

	pos.x = GlobalTrasform.m[6];
	pos.y = GlobalTrasform.m[7];

	return pos;
}

//--------------------------------------------------------------------------------------
// SetPosition: Set the position of the entity.
//
// Param:
//		x: a float for the x of entity.
//		y: a float for the y of enity.
//--------------------------------------------------------------------------------------
void Entity::SetPosition(float x, float y)
{
	localTransform.m[6] = x;
	localTransform.m[7] = y;

	updateGlobalTransform();
}

//--------------------------------------------------------------------------------------
// SetType: Set what type the entity is.
//
// Param:
//		types: a Type enum value.
//--------------------------------------------------------------------------------------
void Entity::SetType(Types types)
{
	this->types = types;
}

//--------------------------------------------------------------------------------------
// Update: Get the Entity type.
//
// Return:
//		Types: Returns the type for the entity.
//--------------------------------------------------------------------------------------
Types Entity::GetType()
{
	return types;
}

//--------------------------------------------------------------------------------------
// LocalToGlobal: Change a localtransform to a globaltransform.
//--------------------------------------------------------------------------------------
void Entity::LocalToGlobal()
{
	localTransform = GlobalTrasform;
}

//--------------------------------------------------------------------------------------
// Update: A virtual function to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//--------------------------------------------------------------------------------------
void Entity::Update(float deltaTime)
{

}

//--------------------------------------------------------------------------------------
// Draw: A virtual function to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void Entity::Draw(Renderer2D* renderer2D)
{
	// if it has a texture draw it
	if (texture)
	{
		renderer2D->drawSpriteTransformed3x3(texture, GlobalTrasform);
	}

	// Draw bounding boxes
	renderer2D->drawLine(boundingBox.LowerLeft.x, boundingBox.LowerLeft.y, boundingBox.UpperRight.x, boundingBox.UpperRight.y, 10, 0);

	// Draw all of the children in entity
	for (int i = 0; i < children.size(); i++)
	{
		children[i]->Draw(renderer2D);
	}
}