#include "Antenna.h"

Antenna::Antenna(char* textureUrl) : Entity(textureUrl)
{
	rotSpeed = 3.14f;
}

Antenna::~Antenna()
{
}

void Antenna::Update(float deltaTime)
{
	Matrix3 rottemp;
	float rot = 0;

	rot = rotSpeed * deltaTime;

	rottemp.setRotateZ(rot);
	localTransform = localTransform * rottemp;

	updateGlobalTransform();
}
