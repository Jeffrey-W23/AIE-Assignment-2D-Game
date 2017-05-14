// #include, using, etc
#include "Input.h"
#include "turret.h"
#include "VectorCast.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//
// Param: 
//		textureUrl: Takes in a char for specifying a texture url in texture file location.
//--------------------------------------------------------------------------------------
turret::turret(char* textureUrl) : Entity(textureUrl)
{
	// Create an Antenna.
	antenna = new Antenna("rock_large");
	
	// Set its parent to Turret.
	antenna->setParent(this);
	
	// Set turrets child to Antenna.
	this->setChild(antenna);

	// initialize rotSpeed.
	rotSpeed = 3.14f;

	// Create 15 bullets.
	for (int i = 0; i < 15; i++)
	{
		Vector2 temp;
		bullets[i] = new Bullet(nullptr, temp, 5.0f);
	}

	// initialize bulletCount.
	bulletCount = 0;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
turret::~turret()
{
	// Delete antenna
	delete antenna;

	// delete bullets
	for (int i = 0; i < 15; i++)
	{
		delete bullets[i];
	}
}

//--------------------------------------------------------------------------------------
// Update: A virtual function from entity to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//--------------------------------------------------------------------------------------
void turret::Update(float deltaTime)
{
	// A new instance of Input.
	Input* input = Input::getInstance();

	// Create a temp rot float and Maxtrix.
	Matrix3 rottemp;
	float rot = 0;

	// Rotate the turret on these key presses.
	if (input->isKeyDown(INPUT_KEY_E))
		rot = rotSpeed * deltaTime;

	if (input->isKeyDown(INPUT_KEY_Q))
		rot = -rotSpeed * deltaTime;

	// Fire the turret. Fires Bullets.
	if (input->wasKeyPressed(INPUT_KEY_SPACE))
	{
		// Move the bullet.
		Vector3 dir1 = GlobalTrasform[1];
		bullets[bulletCount]->SetDir(CastTo<Vector2>(dir1));
		bullets[bulletCount]->SetPosition(GetPosition().x, GetPosition().y);
		++bulletCount;

		// If the bullket count get to 15 reset it.
		if (bulletCount >= 15)
		{
			bulletCount = 0;
		}
	}

	// Decouple the hierarchy  between turret and antenna.
	if (input->isKeyDown(INPUT_KEY_LEFT_SHIFT))
	{
		antenna->LocalToGlobal();
		antenna->setParent(nullptr);
	}

	// Couple the hierarchy  between turret and antenna.
	if (input->isKeyDown(INPUT_KEY_RIGHT_SHIFT))
	{
		antenna->NewMatrix();
		antenna->setParent(this);
	}

	// Update each bullet.
	for (int i = 0; i < 15; i++)
	{
		bullets[i]->Update(deltaTime);
	}

	// Set the rotation and update the local and global transform for turret.
	rottemp.setRotateZ(rot);
	localTransform = localTransform * rottemp;
	updateGlobalTransform();

	// Update the antenna.
	antenna->Update(deltaTime);
}

//--------------------------------------------------------------------------------------
// Draw: A virtual function from entity to render (or "draw") objects to the screen.
//
// Param:
//		renderer2D: a pointer to Renderer2D for rendering objects to screen.
//--------------------------------------------------------------------------------------
void turret::Draw(Renderer2D* renderer2D)
{
	// Draw each of the bullets in the array.
	for (int i = 0; i < 15; i++)
	{
		bullets[i]->Draw(renderer2D);
	}

	// Call draw on enity.
	Entity::Draw(renderer2D);
}
