#pragma once
#include "Matrix3.h"
#include "Vector2.h"
#include <vector>
#include "Collider.h"
#include "Renderer2D.h"
#include "Texture.h"
using namespace std;
using namespace aie;

class Entity
{
public:
	Entity(char textureUrl[32]);
	~Entity();

	void setParent(Entity* sParent);
	void setChild(Entity* sChild);

	void updateGlobalTransform();

	Collider& GetCollider();
	Vector2 GetPosition();

	void SetPosition(float x, float y);

	virtual void Update(float deltaTime);
	virtual void Draw(Renderer2D* renderer2D);

protected:
	Entity* Parent;
	vector<Entity*> children;

	Matrix3 localTransform;
	Matrix3 GlobalTrasform;

	Collider m_Collider;

	Texture* texture;
};