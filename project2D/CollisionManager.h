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
	static void Create();
	static void Destory();
	void AddObject(Entity* pObject);
	void RemoveObject(Entity* pObject);
	Entity* TestCollision(Entity* pObject);

private:
	CollisionManager();
	~CollisionManager();

	static CollisionManager* m_Instance;

	vector<Entity*> m_CollisionList;
};