//#include, using etc
#pragma once
#include "Entity.h"
#include <vector>

//--------------------------------------------------------------------------------------
// Wall object. Inheritance from Entity.
//--------------------------------------------------------------------------------------
class CollisionManager
{
public:
	static CollisionManager* GetInstance();

	//--------------------------------------------------------------------------------------
	// Create: Create a boundingbox.
	//--------------------------------------------------------------------------------------
	static void Create();

	//--------------------------------------------------------------------------------------
	// Destroy: Destory boundingboxes on shut down.
	//--------------------------------------------------------------------------------------
	static void Destory();
	
	//--------------------------------------------------------------------------------------
	// AddObject: Add an object from the collision list.
	//
	// Param:
	//		pObject: An entity for the object you want to add.
	//--------------------------------------------------------------------------------------
	void AddObject(Entity* pObject);

	//--------------------------------------------------------------------------------------
	// RemoveObject: Remove object from the collision list.
	//
	// Param:
	//		pObject: An entity for the object you want to remove.
	//--------------------------------------------------------------------------------------
	void RemoveObject(Entity* pObject);

	//--------------------------------------------------------------------------------------
	// Test Collisions: Different function for different object types to check if colliding.
	//
	// Param:
	//		pObject: The entity to check if its colliding.
	//
	// Returns:
	//		Entity: The entity that is being collided with.
	//--------------------------------------------------------------------------------------
	Entity* TestBoxBoxCollision(Entity* pObject);
	Entity* TestSphereBoxCollision(Entity* pObject);
	/*Entity* TestSphereSphereCollision(Vector2 pos1, Vector2 pos2, float rad1, float rad2);*/
	
	//--------------------------------------------------------------------------------------
	// Bounce: Resolve a collision with a bounce.
	//
	// Param:
	//		pObject: An entity of the object you want to bounce.
	//		dir: A Vector2 for the direction you want the object to bounce.
	//		pos: A Vector2 for the pos of the object.
	//--------------------------------------------------------------------------------------
	Vector2 Bounce(Entity* pObject, Vector2 dir, Vector2 pos);

	//--------------------------------------------------------------------------------------
	// Project: Project the Vector3 for SAT collision testing.
	//
	// Param:
	//		a: A Vector3 a.
	//		b: A Vector3 b
	//
	// Returns:
	//		Vector3: Returns the Vector3 projection of an object.
	//--------------------------------------------------------------------------------------
	static Vector3 Project(Vector3& a, Vector3& b);

	//--------------------------------------------------------------------------------------
	// IsColliding: Check if 2 SAT boundingboxes are colliding.
	//
	// Param:
	//		a: An Entity for an object that can collide
	//		b: An Entity for an object that can collide
	//
	// Returns:
	//		bool: Returns a bool of true or falue for if a collision is happening.
	//--------------------------------------------------------------------------------------
	static bool IsColliding(Entity* a, Entity* b);

private:

	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	CollisionManager();

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	~CollisionManager();
 
	//--------------------------------------------------------------------------------------
	// Instance of the collison manager
	//--------------------------------------------------------------------------------------
	static CollisionManager* m_Instance;

	//--------------------------------------------------------------------------------------
	// A Dynamic array of Enity that can collide.
	//--------------------------------------------------------------------------------------
	vector<Entity*> m_CollisionList;
};