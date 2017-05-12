#pragma once
#include "Entity.h"
#include "Antenna.h"
#include "Bullet.h"

class turret : public Entity
{
public:
	turret(char* textureUrl);
	~turret();

	void Update(float deltaTime);
	void Draw(Renderer2D* renderer2D);

	float rotSpeed;
	Antenna* antenna;
	Bullet* bullets[15];

	int bulletCount;
};