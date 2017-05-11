#include "rect.h"

rect::rect()
{
	pos.x = 0;
	pos.y = 0;
	size.x = 0;
	size.y = 0;
	CalcVertices();
}

rect::rect(Vector3 _size) : rect()
{
	pos.x = 0;
	pos.y = 0;
	size = _size;
	CalcVertices();
}

rect::rect(Vector3 _pos, Vector3 _size) : rect(_size)
{
	pos = _pos;
	CalcVertices();
}

rect::~rect()
{

}

void rect::MoveBy(Vector3 by)
{
	pos = pos + by;
	UpdateVertices();
}

void rect::MoveTo(Vector3 to)
{
	pos = to;
	UpdateVertices();
}

void rect::RotateBy(Matrix3 by)
{
	rot = rot * by;
	UpdateVertices();
}

void rect::SetSize(Vector3 _size)
{
	size = _size;
	CalcVertices();
}

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

void rect::UpdateVertices()
{
	LowerLeft = (rot * OriginalLowerLeft) + pos;
	LowerRight = (rot * OriginalLowerRight) + pos;
	UpperLeft = (rot * OriginalUpperLeft) + pos;
	UpperRight = (rot * OriginalUpperRight) + pos;
}