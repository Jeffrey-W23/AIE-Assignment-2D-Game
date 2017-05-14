// #include, using, etc
#include "rect.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
rect::rect()
{
	pos.x = 0;
	pos.y = 0;
	size.x = 0;
	size.y = 0;
	CalcVertices();
}

//--------------------------------------------------------------------------------------
// Constructor passing in Vector3 _size.
//
// Param: 
//		_size: a Vector3 for rect size.
//--------------------------------------------------------------------------------------
rect::rect(Vector3 _size) : rect()
{
	pos.x = 0;
	pos.y = 0;
	size = _size;
	CalcVertices();
}

//--------------------------------------------------------------------------------------
// Default passing in Vector3 _pos and Vector3 _size.
//
// Param: 
//		_pos: a Vector3 for rect position.
//		_size: a Vector3 for rect size.
//--------------------------------------------------------------------------------------
rect::rect(Vector3 _pos, Vector3 _size) : rect(_size)
{
	pos = _pos;
	CalcVertices();
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
rect::~rect()
{

}

//--------------------------------------------------------------------------------------
// MoveBy: Move the rect object by a specified amount.
//
// Param:
//		by: a Vector3 value for specifying how much to move the rect object by.
//--------------------------------------------------------------------------------------
void rect::MoveBy(Vector3 by)
{
	pos = pos + by;
	UpdateVertices();
}

//--------------------------------------------------------------------------------------
// MoveTo: Move the rect object to a specified position.
//
// Param:
//		To: a Vector3 value for specifying where to reposition rect to.
//--------------------------------------------------------------------------------------
void rect::MoveTo(Vector3 to)
{
	pos = to;
	UpdateVertices();
}

//--------------------------------------------------------------------------------------
// RotateBy: Rotate the rect object by a specified amount.
//
// Param:
//		by: a Vector3 value for specifying how much to rotate the rect object by.
//--------------------------------------------------------------------------------------
void rect::RotateBy(Matrix3 by)
{
	rot = rot * by;
	UpdateVertices();
}

//--------------------------------------------------------------------------------------
// SetSize: Set the size of the rect object.
//
// Param:
//		_size: specify the size of the rect with a Vector3 value.
//--------------------------------------------------------------------------------------
void rect::SetSize(Vector3 _size)
{
	size = _size;
	CalcVertices();
}

//--------------------------------------------------------------------------------------
// CalcVertices: Calculate the vertcies of each corner.
//--------------------------------------------------------------------------------------
void rect::CalcVertices()
{
	OriginalLowerLeft.x = ((-size.x / 2));
	OriginalLowerLeft.y = ((-size.y / 2));

	OriginalLowerRight.x = ((size.x / 2));
	OriginalLowerRight.y = ((-size.y / 2));

	OriginalUpperLeft.x = ((-size.x / 2));
	OriginalUpperLeft.y = ((size.y / 2));

	OriginalUpperRight.x = ((size.x / 2));
	OriginalUpperRight.y = ((size.y / 2));
	
	UpdateVertices();
}

//--------------------------------------------------------------------------------------
// UpdateVertices: Update the vertices of each corner.
//--------------------------------------------------------------------------------------
void rect::UpdateVertices()
{
	LowerLeft = (rot * OriginalLowerLeft) + pos;
	LowerRight = (rot * OriginalLowerRight) + pos;
	UpperLeft = (rot * OriginalUpperLeft) + pos;
	UpperRight = (rot * OriginalUpperRight) + pos;
}