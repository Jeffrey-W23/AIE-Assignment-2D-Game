//#include, using etc
#pragma once
#include "Matrix3.h"
#include "Vector2.h"
#include <vector>
#include "Collider.h"
#include "Renderer2D.h"
#include "Texture.h"
using namespace std;
using namespace aie;

// Entity Object
class Entity
{
public:

	// Default Constructor
	Entity(char textureUrl[32]);
	
	// Default Destructor
	~Entity();

	// Set Parent and child
	void setParent(Entity* sParent);
	void setChild(Entity* sChild);

	// Update the Global Transform
	void updateGlobalTransform();

	// Get position and if colliding
	Collider& GetCollider();
	Vector2 GetPosition();

	// Set postion
	void SetPosition(float x, float y);

	// Update and draw function
	virtual void Update(float deltaTime);
	virtual void Draw(Renderer2D* renderer2D);

protected:

	// Parent and draw
	Entity* Parent;
	vector<Entity*> children;

	// Local and global transforms
	Matrix3 localTransform;
	Matrix3 GlobalTrasform;

	// collider
	Collider m_Collider;

	// texture
	Texture* texture;
};