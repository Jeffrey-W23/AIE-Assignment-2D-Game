#pragma once
#include "Vector3.h"

class rect
{
public:
	rect();
	rect(Vector3 _size);
	rect(Vector3 _pos, Vector3 _size);
	~rect();

	void MoveBy(Vector3 by);
	void MoveTo(Vector3 To);
	void SetSize(Vector3 _size);

	Vector3 UpperLeft;
	Vector3 UpperRight;
	Vector3 LowerLeft;
	Vector3 LowerRight;

private:
	void UpdateVertices();

	Vector3 pos;
	Vector3 size;
};

