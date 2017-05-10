#include "rect.h"

rect::rect()
{
	pos.x = 0;
	pos.y = 0;
	size.x = 0;
	size.y = 0;
	UpdateVertices();
}

rect::rect(Vector2 _size) : rect()
{
	pos.x = 0;
	pos.y = 0;
	size = _size;
	UpdateVertices();
}

rect::rect(Vector2 _pos, Vector2 _size) : rect(_size)
{
	pos = _pos;
	UpdateVertices();
}

rect::~rect()
{

}

void rect::MoveBy(Vector2 by)
{
	pos = pos + by;
	UpdateVertices();
}

void rect::MoveTo(Vector2 to)
{
	pos = to;
	UpdateVertices();
}

void rect::SetSize(Vector2 _size)
{
	size = _size;
	UpdateVertices();
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