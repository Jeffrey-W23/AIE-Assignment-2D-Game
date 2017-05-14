// #include, using, etc
#include "Player.h"
#include "VectorCast.h"
#include "Vector3.h"
#include "Matrix3.h"
#include "Texture.h"
#include "Input.h"
#include "CollisionManager.h"
#include <iostream>
using namespace std;
using namespace aie;

//--------------------------------------------------------------------------------------
// Default Constructor.
//
// Param: 
//		textureUrl: Takes in a char for specifying a texture url in texture file location.
//--------------------------------------------------------------------------------------
Player::Player(char* textureUrl) : Entity(textureUrl)
{
	// Create a collidable object for walls.
	CollisionManager* collider = CollisionManager::GetInstance();
	collider->AddObject(this);

	// Create a Turret.
	Turret = new turret("rock_large");

	// Set the players child to Turret.
	Turret->setParent(this);
	this->setChild(Turret);

	// initialize rotSpeed.
	rotSpeed = 3.14f;
	
	// Set the type of object to wall
	this->SetType(PLAYER);
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Player::~Player()
{
	delete Turret;
}

//--------------------------------------------------------------------------------------
// Update: A virtual function from entity to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//--------------------------------------------------------------------------------------
void Player::Update(float deltaTime)
{
	// A new instance of Input.
	Input* input = Input::getInstance();

	// Set temp varibles for position and rotation
	Vector2 pos;
	Matrix3 temp;
	Matrix3 rottemp;
	float rot = 0;

	// Move the player with WASD
	if (input->isKeyDown(INPUT_KEY_W))
		pos.y = 150 * deltaTime;

	if (input->isKeyDown(INPUT_KEY_S))
		pos.y = -150 * deltaTime;

	if (input->isKeyDown(INPUT_KEY_A))
		rot = rotSpeed * deltaTime;

	if (input->isKeyDown(INPUT_KEY_D))
		rot = -rotSpeed * deltaTime;

	// Set the position and rotation and update the local and global transform.
	rottemp.setRotateZ(rot);
	temp.setPostionv(pos);
	localTransform = localTransform * rottemp;
	localTransform = localTransform * temp;
	updateGlobalTransform();
	
	// Bind the boundingbox with the player. (for SAT collision.)
	boundingBox.MoveTo(CastTo<Vector3>(GetPosition()));
	boundingBox.RotateBy(rottemp);

	// Update Turret.
	Turret->Update(deltaTime);

	// Test Collision
	CollisionManager* pCollision = CollisionManager::GetInstance();
	Entity* colliding = pCollision->TestBoxBoxCollision(this);

	// Check if the Player is colliding with a wall
	if (colliding != nullptr && colliding->GetType() == WALL)
	{
		// Debug message for console if the player hits a wall
		cout << "HIT!" << endl;
	}
}

//--------------------------------------------------------------------------------------
// Draw: A virtual function from entity to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void Player::Draw(Renderer2D* renderer2D)
{
	// Set the camera location
	renderer2D->setCameraPos(GlobalTrasform[2][0] - 640, GlobalTrasform[2][1] - 360);
	renderer2D->begin();

	// Call Enity draw.
	Entity::Draw(renderer2D);
}