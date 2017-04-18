#pragma once
#include "Matrix3.h"
#include "Vector2.h"
#include <vector>
#include "Collider.h"
using namespace std;

class Entity
{
public:
	Entity();
	~Entity();
	void setParent(Entity* sParent);
	void setChild(Entity* sChild);
	void updateGlobalTransform();
	Collider& GetCollider();
	Vector2 GetPosition();

protected:
	Entity* Parent;
	vector<Entity*> children;

	Matrix3 localTransform;
	Matrix3 GlobalTrasform;

	Collider m_Collider;
};