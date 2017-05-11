#pragma once
#include "Vector3.h"
#include "Matrix3.h"

class rect
{
public:
	rect();
	rect(Vector3 _size);
	rect(Vector3 _pos, Vector3 _size);
	~rect();

	void MoveBy(Vector3 by);
	void MoveTo(Vector3 To);
	void RotateBy(Matrix3 by);
	void SetSize(Vector3 _size);

	Vector3 UpperLeft;
	Vector3 UpperRight;
	Vector3 LowerLeft;
	Vector3 LowerRight;

private:
	void CalcVertices();
	void UpdateVertices();

	Vector3 OriginalUpperLeft;
	Vector3 OriginalUpperRight;
	Vector3 OriginalLowerLeft;
	Vector3 OriginalLowerRight;
	
	Matrix3 rot;
	Vector3 pos;
	Vector3 size;
};

