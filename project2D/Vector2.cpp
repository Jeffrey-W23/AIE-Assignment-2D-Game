#include "Vector2.h"

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::~Vector2()
{
}

Vector2 Vector2::operator+(const Vector2& rhs)
{
	Vector2 result;
	result.x = x + rhs.x;
	result.y = y + rhs.y;

	return result;
}

Vector2 Vector2::operator-(const Vector2& rhs)
{
	Vector2 result;
	result.x = x - rhs.x;
	result.y = y - rhs.y;

	return result;
}

Vector2 Vector2::operator*(float rhs)
{
	Vector2 result;
	result.x = x * rhs;
	result.y = y * rhs;

	return result;
}

Vector2 operator*(float lhs, const Vector2& rhs)
{
	Vector2 result;
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;

	return result;
}

float Dot(Vector2 rhs)
{
	// return dot product
}

// Allow negative vector
Vector2 Vector2::operator-()
{
	Vector2 result;
	result.x = -x;
	result.y = -y;

	return result;
}
