// #include, using, etc
#include "Vector2.h"

// Default Constructor
Vector2::Vector2()
{
	x = 0;
	y = 0;
}

// Constructor passing in 2 floats
Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

// Default Destructor
Vector2::~Vector2()
{
}

// Addition
Vector2 Vector2::operator+(const Vector2& rhs)
{
	Vector2 result;
	result.x = x + rhs.x;
	result.y = y + rhs.y;

	return result;
}

// Subtraction
Vector2 Vector2::operator-(const Vector2& rhs)
{
	Vector2 result;
	result.x = x - rhs.x;
	result.y = y - rhs.y;

	return result;
}

// Divide
Vector2 Vector2::operator/(const float rhs)
{
	Vector2 result;
	result.x = x / rhs;
	result.y = y / rhs;

	return result;
}

// Multiply vector by float
Vector2 Vector2::operator*(const float rhs)
{
	Vector2 result;
	result.x = x * rhs;
	result.y = y * rhs;

	return result;
}

// Multiply float by vector ( out side of class so we can order )
Vector2 operator*(float lhs, const Vector2& rhs)
{
	Vector2 result;
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;

	return result;
}

// Dot product
float Vector2::DotProduct(const Vector2& rhs)
{
	float result;
	result = x * rhs.x + y * rhs.y;
	return result;
}

// Magnititude
float Vector2::Magnititude()
{
	float result;
	result = sqrtf(x*x + y*y);
	return result;
}

// Magnititude Squared
float Vector2::MagnititudeSquared()
{
	float result;
	result = x*x + y*y;
	return result;
}

// Normalise
void Vector2::Normalise()
{
	float mag = Magnititude();

	if (mag != 0)
	{
		x = x / mag;
		y = y / mag;
	}
}

// Normalised
Vector2 Vector2::Normalised(Vector2 data)
{
	float mag = data.Magnititude();

	Vector2 result;

	if (mag != 0)
	{
		result.x = data.x / mag;
		result.y = data.y / mag;
		
		return result;
	}
}

// Allow negative vector
Vector2 Vector2::operator-()
{
	Vector2 result;
	result.x = -x;
	result.y = -y;

	return result;
}

// Greater then operator
bool Vector2::operator>(const Vector2 rhs)
{
	return (x > rhs.x && y > rhs.y);
}

// Less then operator
bool Vector2::operator<(const Vector2 rhs)
{
	return (x < rhs.x && y < rhs.y);

}

// Override plus equels
Vector2 Vector2::operator+=(const Vector2& rhs)
{
	x += rhs.x;
	y += rhs.y;

	return *this;
}

// Override minus equels
Vector2 Vector2::operator-=(const Vector2& rhs)
{
	x -= rhs.x;
	y -= rhs.y;

	return *this;
}

// Override multiply equels
Vector2 Vector2::operator*=(const float rhs)
{
	Vector2 result;
	result.x = x *= rhs;
	result.y = y *= rhs;

	return result;
}

// Override divide equels
Vector2 Vector2::operator/=(const float rhs)
{
	Vector2 result;
	result.x = x /= rhs;
	result.y = y /= rhs;

	return result;
}