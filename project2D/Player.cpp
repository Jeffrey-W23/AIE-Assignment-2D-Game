#include "Player.h"

Player::Player(char textureUrl[32]) : Entity(textureUrl)
{
	CollisionManager* collider = CollisionManager::GetInstance();

	// Body
	collider->AddObject(this);

	//ARMS
	// LeftTopArm
	/*Entity* LeftTopArm = new Entity("arm");
	LeftTopArm->setParent(this);
	this->setChild(LeftTopArm);
	collider->AddObject(LeftTopArm);
	LeftTopArm->SetPosition(-15, 0);*/
}

Player::~Player()
{
}

void Player::Draw(Renderer2D* renderer2D)
{
	renderer2D->setCameraPos(GlobalTrasform[2][0] - 640, GlobalTrasform[2][1] - 360);
	renderer2D->begin();

	Entity::Draw(renderer2D);
}

void Player::Update(float deltaTime)
{
	//input example
	Input* input = Input::getInstance();

	Vector2 pos;
	Matrix3 temp;

	// use arrow keys to move camera
	if (input->isKeyDown(INPUT_KEY_W))
		pos.y = 50 * deltaTime;

	if (input->isKeyDown(INPUT_KEY_S))
		pos.y = -50 * deltaTime;

	if (input->isKeyDown(INPUT_KEY_Q))
		pos.x = -50 * deltaTime;

	if (input->isKeyDown(INPUT_KEY_E))
		pos.x = 50 * deltaTime;

	temp.setPostionv(pos);
	localTransform = localTransform * temp;

	updateGlobalTransform();

	
	// Test Collision
	/*CollisionManager* pCollision = CollisionManager::GetInstance();

	bool colliding = pCollision->TestCollision(this);

	if (colliding)
	{
		cout << "HIT!" << endl;
	}*/
}