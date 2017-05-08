#pragma once
#include "Entity.h"

class Antenna : public Entity
{
public:
	Antenna(char* textureUrl);
	~Antenna();

	void Update(float deltaTime);

	float rotSpeed;
};