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
	Entity* TestCollision(Entity* pObject);

private:
	// Constructor and destructor
	CollisionManager();
	~CollisionManager();

	// 
	static CollisionManager* m_Instance;

	// a list of entity that can collid
	vector<Entity*> m_CollisionList;
};