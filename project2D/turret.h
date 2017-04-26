#pragma once
#include "Entity.h"
#include "Input.h"
#include "CollisionManager.h"

class turret : public Entity
{
public:
	turret(char textureUrl[32]);
	~turret();

	void Update(float deltaTime);
	/*void Draw(Renderer2D* renderer2D);*/

	float rotSpeed;
};