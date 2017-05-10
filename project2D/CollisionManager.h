//#include, using etc
#pragma once
#include "Entity.h"
#include <vector>
#include <iostream>
#include "Collider.h"
using namespace std;

class CollisionManager
{
public:
	static CollisionManager* GetInstance();

	// create and delete colliders
	static void Create();
	static void Destory();
	
	// Add remove objects from collision list
	void AddObject(Entity* pObject);
	void RemoveObject(Entity* pObject);
	
	// Test collision
	Entity* TestBoxBoxCollision(Entity* pObject);
	Entity* TestSphereBoxCollision(Entity* pObject);
	/*Entity* TestSphereSphereCollision(Vector2 pos1, Vector2 pos2, float rad1, float rad2);*/
	Vector2 Bounce(Entity* pObject, Vector2 dir, Vector2 pos);


private:
	// Constructor and destructor
	CollisionManager();
	~CollisionManager();

	// 
	static CollisionManager* m_Instance;

	// a list of entity that can collid
	vector<Entity*> m_CollisionList;
};