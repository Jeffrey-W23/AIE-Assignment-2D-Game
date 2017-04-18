#include "Matrix2.h"

Matrix2::Matrix2()
{
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = 1;
}

Matrix2::Matrix2(float Xx, float Xy, float Yx, float Yy)
{
	m[0] = Xx;
	m[1] = Xy;
	m[2] = Yx;
	m[3] = Yy;
}

Matrix2::~Matrix2()
{
}

Vector2 Matrix2::operator*(const Vector2& rhs)
{
	Vector2 result;

	result.x = m[0] * rhs.x + m[2] * rhs.y;
	result.y = m[1] * rhs.x + m[3] * rhs.y;

	return result;
}

Matrix2 Matrix2::operator*(const Matrix2& rhs)
{
	Matrix2 result;

	result.m[0] = m[0] * rhs.m[0] + m[2] * rhs.m[1];
	result.m[1] = m[1] * rhs.m[0] + m[3] * rhs.m[1];

	result.m[2] = m[0] * rhs.m[2] + m[2] * rhs.m[3];
	result.m[3] = m[1] * rhs.m[2] + m[3] * rhs.m[3];

	return result;
}

// Sub-script operator returning a reference 
Vector2& Matrix2::operator[](const int rhs)
{
	return *(Vector2*)(m + 2 * rhs);
}

// Cast operator to float pointer
Matrix2::operator float*()
{
	return &m[0];
}

// Set Rotation
void Matrix2::setRotate(const float a)
{
	m[0] = cosf(a);
	m[1] = sinf(a);
	m[2] = -sinf(a);
	m[3] = cosf(a);
}

// Set Scale
void Matrix2::setScale(const float x, const float y)
{
	m[0] = x;
	m[1] = 0;
	m[2] = 0;
	m[3] = y;
}