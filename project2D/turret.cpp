#include "turret.h"

turret::turret(char* textureUrl) : Entity(textureUrl)
{
	CollisionManager* collider = CollisionManager::GetInstance();
	collider->AddObject(this);

	antenna = new Antenna("rock_large");
	antenna->setParent(this);
	this->setChild(antenna);

	rotSpeed = 3.14f;
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

	rottemp.setRotateZ(rot);
	localTransform = localTransform * rottemp;

	updateGlobalTransform();

	antenna->Update(deltaTime);


	// Test Collision
	/*CollisionManager* pCollision = CollisionManager::GetInstance();

	bool colliding = pCollision->TestCollision(this);

	if (colliding)
	{
	cout << "HIT!" << endl;
	}*/
}

//void turret::Draw(Renderer2D* renderer2D)
//{
//	renderer2D->begin();
//}
