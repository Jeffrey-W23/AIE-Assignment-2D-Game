#include "rect.h"

rect::rect()
{
	pos.x = 0;
	pos.y = 0;
	size.x = 0;
	size.y = 0;
}

rect::rect(Vector3 _size) : rect()
{
	pos.x = 0;
	pos.y = 0;
	size = _size;
}

rect::rect(Vector3 _pos, Vector3 _size) : rect(_size)
{
	pos = _pos;
}

rect::~rect()
{

}

void rect::MoveBy(Vector3 by)
{
	pos = pos + by;
}

void rect::MoveTo(Vector3 to)
{
	pos = to;
}

void rect::SetSize(Vector3 _size)
{
	size = _size;
}

void rect::UpdateVertices()
{
	LowerLeft.x = (pos.x - (size.x / 2));
	LowerLeft.y = (pos.y - (size.y / 2));

	LowerRight.x = (pos.x + (size.x / 2));
	LowerRight.y = (pos.y - (size.y / 2));

	UpperLeft.x = (pos.x - (size.x / 2));
	UpperLeft.y = (pos.y + (size.y / 2));

	UpperRight.x = (pos.x + (size.x / 2));
	UpperRight.y = (pos.y + (size.y / 2));
}