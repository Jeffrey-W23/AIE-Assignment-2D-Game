#include "Antenna.h"

Antenna::Antenna(char* textureUrl) : Entity(textureUrl)
{
	rotSpeed = 3.14f;

	Matrix3 temppos;
	temppos.setPostionv(Vector2(50, 50));

	localTransform = localTransform * temppos;
	updateGlobalTransform();
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
