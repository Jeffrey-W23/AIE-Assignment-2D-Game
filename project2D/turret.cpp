#include "turret.h"
#include "VectorCast.h"

turret::turret(char* textureUrl) : Entity(textureUrl)
{
	antenna = new Antenna("rock_large");
	antenna->setParent(this);
	this->setChild(antenna);

	rotSpeed = 3.14f;

	for (int i = 0; i < 15; i++)
	{
		Vector2 temp;
		bullets[i] = new Bullet(nullptr, temp, 5.0f);
	}

	bulletCount = 0;
}

turret::~turret()
{
}

void turret::Update(float deltaTime)
{
	//input example
	Input* input = Input::getInstance();

	Matrix3 rottemp;
	float rot = 0;

	if (input->isKeyDown(INPUT_KEY_E))
		rot = rotSpeed * deltaTime;

	if (input->isKeyDown(INPUT_KEY_Q))
		rot = -rotSpeed * deltaTime;

	if (input->wasKeyPressed(INPUT_KEY_SPACE))
	{
		Vector3 dir1 = GlobalTrasform[1];
		bullets[bulletCount]->SetDir(CastTo<Vector2>(dir1));
		bullets[bulletCount]->SetPosition(GetPosition().x, GetPosition().y);
		++bulletCount;

		if (bulletCount >= 15)
		{
			bulletCount = 0;
		}
	}

	for (int i = 0; i < 15; i++)
	{
		bullets[i]->Update(deltaTime);
	}

	rottemp.setRotateZ(rot);
	localTransform = localTransform * rottemp;

	updateGlobalTransform();

	antenna->Update(deltaTime);
}

void turret::Draw(Renderer2D* renderer2D)
{
	for (int i = 0; i < 15; i++)
	{
		bullets[i]->Draw(renderer2D);
	}

	Entity::Draw(renderer2D);
}
