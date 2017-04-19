#include "Player.h"

Player::Player(char textureUrl[32]) : Entity(textureUrl)
{
	CollisionManager* collider = CollisionManager::GetInstance();

	// Body
	collider->AddObject(this);

	// Head
	Entity* Head = new Entity("Head");
	Head->setParent(this);
	setChild(Head);
	collider->AddObject(Head);

	//ARMS
	// LeftTopArm
	Entity* LeftTopArm = new Entity("LeftTop");
	LeftTopArm->setParent(this);
	this->setChild(LeftTopArm);
	collider->AddObject(LeftTopArm);

	// LeftBottomArm
	Entity* LeftBottomArm = new Entity("LeftBottom");
	LeftBottomArm->setParent(LeftTopArm);
	LeftTopArm->setChild(LeftBottomArm);
	collider->AddObject(LeftBottomArm);

	// RightTopArm
	Entity* RightTopArm = new Entity("RightTopArm");
	RightTopArm->setParent(this);
	this->setChild(RightTopArm);
	collider->AddObject(RightTopArm);

	// RightBottomArm
	Entity* RightBottomArm = new Entity("LeftBottom");
	RightBottomArm->setParent(RightTopArm);
	RightTopArm->setChild(RightBottomArm);
	collider->AddObject(RightBottomArm);
	//ARMS

	// LEGS
	// LeftTopLeg
	Entity* LeftTopLeg = new Entity("LeftTop");
	LeftTopLeg->setParent(this);
	this->setChild(LeftTopLeg);
	collider->AddObject(LeftTopLeg);

	// LeftBottomLeg
	Entity* LeftBottomLeg = new Entity("LeftBottom");
	LeftBottomLeg->setParent(LeftTopLeg);
	LeftTopLeg->setChild(LeftBottomLeg);
	collider->AddObject(LeftBottomLeg);

	// RightTopLeg
	Entity* RightTopLeg = new Entity("RightTopArm");
	RightTopLeg->setParent(this);
	this->setChild(RightTopLeg);
	collider->AddObject(RightTopLeg);

	// RightBottomLeg
	Entity* RightBottomLeg = new Entity("LeftBottom");
	RightBottomLeg->setParent(RightTopLeg);
	RightTopLeg->setChild(RightBottomLeg);
	collider->AddObject(RightBottomLeg);
	// LEGS
}

Player::~Player()
{
}

void Player::Draw(Renderer2D* renderer2D)
{
	renderer2D->setCameraPos(GlobalTrasform[2][0] - 640, GlobalTrasform[2][1] - 360);
	renderer2D->begin();

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