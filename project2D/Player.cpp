#include "Player.h"

Player::Player()
{
	playerTexture = new Texture("./textures/ship.png");
	rotSpeed = 3.14f;
	speed = 100.0f;
}

Player::~Player()
{
}

void Player::Draw(Renderer2D* renderer2D)
{
	renderer2D->setCameraPos(GlobalTrasform[2][0] - 640, GlobalTrasform[2][1] - 360);
	renderer2D->begin();
	renderer2D->drawSpriteTransformed3x3(playerTexture, localTransform);
}

void Player::Update(float deltaTime)
{
	// input example
	Input* input = Input::getInstance();

	Vector2 pos;
	Matrix3 temp;
	float rot = 0;
	Matrix3 tempRotation;

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
		rot = rotSpeed * deltaTime;

	if (input->isKeyDown(INPUT_KEY_D))
		rot -= rotSpeed * deltaTime;

	tempRotation.setRotateZ(rot);
	localTransform = localTransform * tempRotation;

	temp.setPostionv(pos);
	localTransform = localTransform * temp;

	updateGlobalTransform();
}