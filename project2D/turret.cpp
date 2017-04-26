#include "turret.h"

turret::turret(char textureUrl[32]) : Entity(textureUrl)
{
	CollisionManager* collider = CollisionManager::GetInstance();
	collider->AddObject(this);

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

	if (input->isKeyDown(INPUT_KEY_Z))
		rot = rotSpeed * deltaTime;

	if (input->isKeyDown(INPUT_KEY_X))
		rot = -rotSpeed * deltaTime;

	rottemp.setRotateZ(rot);
	localTransform = localTransform * rottemp;

	updateGlobalTransform();


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
