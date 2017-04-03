#include "Matrix2.h"

Matrix2::Matrix2()
{
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = 1; // for three we use 9  // for four we use 16
	// diag ones
}

Matrix2::Matrix2(float Xx, float Yx, float Xy, float Yy)
{
	m[0] = Xx;
	m[1] = Yx;
	m[2] = Xy;
	m[3] = Yy; //slide 5 // 
}

Matrix2::~Matrix2()
{
}

Vector2 Matrix2::operator*(const Vector2& rhs)
{
	Vector2 result;

	result.x = m[0] * rhs.x + m[1] * rhs.y;
	result.y = m[2] * rhs.x + m[3] * rhs.y;

	return result;
}

Matrix2 Matrix2::operator*(const Matrix2& rhs)
{
	Matrix2 result;

	result.m[0] = m[0] * rhs.m[0] + m[1] * rhs.m[2];
	result.m[1] = m[0] * rhs.m[1] + m[1] * rhs.m[3];

	result.m[2] = m[2] * rhs.m[0] + m[3] * rhs.m[2];
	result.m[3] = m[2] * rhs.m[1] + m[3] * rhs.m[3];

	return result;
}
