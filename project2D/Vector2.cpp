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

Vector2 Vector2::operator/(const Vector2& rhs)
{
	Vector2 result;
	result.x = x / rhs.x;
	result.y = y / rhs.y;

	return result; // float?
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

float DotProduct(const Vector2& rhs)
{
	// return dot product
	Vector2 result;
	result.x * rhs.x + result.y * rhs.y;
	return result;
}

float Magnititude(const Vector2& rhs)
{
	// sqrt x^2 + y^2
}

Vector2 Vector2::operator-()
{
	Vector2 result;
	result.x = -x;
	result.y = -y;

	return result;
}
