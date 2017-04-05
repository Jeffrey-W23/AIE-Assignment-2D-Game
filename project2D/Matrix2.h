#pragma once
#include "Vector2.h"

class Matrix2
{
public:
	Matrix2();
	Matrix2(float Xx, float Xy, float Yx, float Yy);
	~Matrix2();

	Vector2 operator*(const Vector2& rhs);
	Matrix2 operator*(const Matrix2& rhs);

	// Sub-script operator returning a reference 
	Vector2& operator[](const int rhs);

	// Cast operator to float pointer
	operator float*();

	// Set Rotation
	void setRotate(const float a);

	// Set Scale
	void setScale(const float x, const float y);

	float m[4];
};