// #include, using, etc
#include "Antenna.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//
// Param: 
//		textureUrl: Takes in a char for specifying a texture url in texture file location.
//--------------------------------------------------------------------------------------
Antenna::Antenna(char* textureUrl) : Entity(textureUrl)
{
	// initialize rotSpeed.
	rotSpeed = 3.14f;

	// Set the position.
	Matrix3 temppos;
	temppos.setPostionv(Vector2(0, 0));

	// Update the local and global transform.
	localTransform = localTransform * temppos;
	updateGlobalTransform();
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Antenna::~Antenna()
{
}

//--------------------------------------------------------------------------------------
// Update: A virtual function from entity to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//--------------------------------------------------------------------------------------
void Antenna::Update(float deltaTime)
{
	// Create a temp rot float and Maxtrix.
	Matrix3 rottemp;
	float rot = 0;

	// Update rot by deltaTime
	rot = rotSpeed * deltaTime;

	// Set the rotation and update the local and global transform.
	rottemp.setRotateZ(rot);
	localTransform = localTransform * rottemp;
	updateGlobalTransform();
}

//--------------------------------------------------------------------------------------
// NewMatrix: Sets the localtranform to  a new Matrix3
//--------------------------------------------------------------------------------------
void Antenna::NewMatrix()
{
	localTransform = Matrix3();
}
