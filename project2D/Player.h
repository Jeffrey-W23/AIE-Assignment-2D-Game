#pragma once
#include "Entity.h"
#include "Renderer2D.h"
#include "turret.h"

class Player : public Entity
{
public:
	Player(char* textureUrl);
	~Player();

	void Update(float deltaTime);
	void Draw(Renderer2D* renderer2D);

	float rotSpeed;
	turret* Turret;
};