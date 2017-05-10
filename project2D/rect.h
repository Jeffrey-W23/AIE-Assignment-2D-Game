#pragma once
#include "Vector2.h"

class rect
{
public:
	rect();
	rect(Vector2 _size);
	rect(Vector2 _pos, Vector2 _size);
	~rect();

	void MoveBy(Vector2 by);
	void MoveTo(Vector2 To);
	void SetSize(Vector2 _size);

	Vector2 UpperLeft;
	Vector2 UpperRight;
	Vector2 LowerLeft;
	Vector2 LowerRight;

private:
	void UpdateVertices();

	Vector2 pos;
	Vector2 size;
};

