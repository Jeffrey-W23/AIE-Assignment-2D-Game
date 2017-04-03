#pragma once
#include "Vector2.h"

class Matrix2
{
public:
	Matrix2();
	Matrix2(float Xx, float Yx, float Xy, float Yy);
	~Matrix2();

	Vector2 operator*(const Vector2& rhs);
	Matrix2 operator*(const Matrix2& rhs);

	float m[4];
};