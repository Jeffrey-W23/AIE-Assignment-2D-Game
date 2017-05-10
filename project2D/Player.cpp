#include "Player.h"
#include "VectorCast.h"
#include "Vector3.h"

Player::Player(char* textureUrl) : Entity(textureUrl)
{
	CollisionManager* collider = CollisionManager::GetInstance();

	// Create the collider for the player
	collider->AddObject(this);

	Turret = new turret("rock_large");
	Turret->setParent(this);
	this->setChild(Turret);

	rotSpeed = 3.14f;
	this->SetType(PLAYER);
}

Player::~Player()
{
}

void Player::Draw(Renderer2D* renderer2D)
{
	renderer2D->setCameraPos(GlobalTrasform[2][0] - 640, GlobalTrasform[2][1] - 360);
	renderer2D->begin();

	Entity::Draw(renderer2D);
	//renderer2D->drawBox(GetPosition().x, GetPosition().y, m_Collider.m_BR.x * 2, m_Collider.m_BR.y * 2);
	
	//------// draw it? player bounding box //------//
	renderer2D->drawBox(boundingBox.LowerLeft.x, boundingBox.LowerLeft.y, boundingBox.UpperRight.x * 2, boundingBox.UpperRight.y *2);
	renderer2D->drawBox(boundingBox.LowerRight.x, boundingBox.LowerRight.y, boundingBox.UpperRight.x * 2, boundingBox.UpperRight.y * 2);

	renderer2D->drawBox(boundingBox.LowerRight.x, boundingBox.LowerRight.y, boundingBox.UpperRight.x * 2, boundingBox.UpperRight.y * 2);
	renderer2D->drawBox(boundingBox.UpperRight.x, boundingBox.UpperRight.y, boundingBox.UpperRight.x * 2, boundingBox.UpperRight.y * 2);

	renderer2D->drawBox(boundingBox.UpperRight.x, boundingBox.UpperRight.y, boundingBox.UpperRight.x * 2, boundingBox.UpperRight.y * 2);
	renderer2D->drawBox(boundingBox.UpperLeft.x, boundingBox.UpperLeft.y, boundingBox.UpperRight.x * 2, boundingBox.UpperRight.y * 2);

	renderer2D->drawBox(boundingBox.UpperLeft.x, boundingBox.UpperLeft.y, boundingBox.UpperRight.x * 2, boundingBox.UpperRight.y * 2);
	renderer2D->drawBox(boundingBox.LowerLeft.x, boundingBox.LowerLeft.y, boundingBox.UpperRight.x * 2, boundingBox.UpperRight.y * 2);
	//------// draw it? player bounding box //------//
}

void Player::Update(float deltaTime)
{
	//input example
	Input* input = Input::getInstance();

	Vector2 pos;
	Matrix3 temp;
	Matrix3 rottemp;
	float rot = 0;

	// use arrow keys to move camera
	if (input->isKeyDown(INPUT_KEY_W))
		pos.y = 150 * deltaTime;

	if (input->isKeyDown(INPUT_KEY_S))
		pos.y = -150 * deltaTime;

	if (input->isKeyDown(INPUT_KEY_A))
		rot = rotSpeed * deltaTime;

	if (input->isKeyDown(INPUT_KEY_D))
		rot = -rotSpeed * deltaTime;

	rottemp.setRotateZ(rot);
	temp.setPostionv(pos);

	//------// rotate? player bounding box //------//
	boundingBox.UpperLeft.x = *rottemp;
	boundingBox.UpperLeft.y = *rottemp;

	boundingBox.UpperRight.x = *rottemp;
	boundingBox.UpperRight.y = *rottemp;

	boundingBox.LowerLeft.x = *rottemp;
	boundingBox.LowerLeft.y = *rottemp;

	boundingBox.LowerRight.x = *rottemp;
	boundingBox.LowerRight.y = *rottemp;
	//------// rotate? player bounding box //------//

	localTransform = localTransform * rottemp;
	localTransform = localTransform * temp;

	updateGlobalTransform();

	Turret->Update(deltaTime);

	// Test Collision
	CollisionManager* pCollision = CollisionManager::GetInstance();

	Entity* colliding = pCollision->TestBoxBoxCollision(this);

	if (colliding != nullptr && colliding->GetType() == WALL)
	{
		cout << "HIT!" << endl;
		
		// basically how decoupling works
		//this->setParent(nullptr);
		//Turret->setChild();
	}
}