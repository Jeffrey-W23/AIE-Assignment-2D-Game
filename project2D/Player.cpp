#include "Player.h"

Player::Player()
{
	playerTexture = new Texture("./textures/LargeShip.png");
	rotSpeed = 0.42f;
	speed = 100.0f;
	rot = 0;

	CollisionManager::GetInstance()->AddObject(this);
}

Player::~Player()
{
}

void Player::Draw(Renderer2D* renderer2D)
{
	//renderer2D->setCameraPos(GlobalTrasform[2][0] - 640, GlobalTrasform[2][1] - 360);
	renderer2D->setCameraPos(GlobalTrasform[2][0], GlobalTrasform[2][1]);
	renderer2D->setRotation(rot);
	renderer2D->begin();
	renderer2D->drawSpriteTransformed3x3(playerTexture, localTransform);
}

void Player::Update(float deltaTime)
{
	// input example
	Input* input = Input::getInstance();

	Vector2 pos;
	Matrix3 temp;
	Matrix3 tempRotation;
	float shiprot = 0;
	// use arrow keys to move camera
	if (input->isKeyDown(INPUT_KEY_W))
		pos.y = speed * deltaTime;

	if (input->isKeyDown(INPUT_KEY_S))
		pos.y = -speed * deltaTime;

	if (input->isKeyDown(INPUT_KEY_Q))
		pos.x = -speed * deltaTime;

	if (input->isKeyDown(INPUT_KEY_E))
		pos.x = speed * deltaTime;

	if (input->isKeyDown(INPUT_KEY_A))
		shiprot -= rotSpeed * deltaTime;

	if (input->isKeyDown(INPUT_KEY_D))
		shiprot += rotSpeed * deltaTime;

	tempRotation.setRotateZ(-shiprot);
	rot += shiprot;
	localTransform = localTransform * tempRotation;

	temp.setPostionv(pos);
	localTransform = localTransform * temp;

	updateGlobalTransform();

	// Test Collision
	CollisionManager* pCollision = CollisionManager::GetInstance();

	bool colliding = pCollision->TestCollision(this);

	if (colliding)
	{
		cout << "HIT!" << endl;
	}
}