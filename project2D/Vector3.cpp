// #include, using, etc
#include "Vector3.h"

// Default Constructor
Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

// Constructor passing in 2 floats
Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

// Default Destructor
Vector3::~Vector3()
{
}

// Addition
Vector3 Vector3::operator+(const Vector3& rhs)
{
	Vector3 result;
	result.x = x + rhs.x;
	result.y = y + rhs.y;
	result.z = z + rhs.z;

	return result;
}

// Subtraction
Vector3 Vector3::operator-(const Vector3& rhs)
{
	Vector3 result;
	result.x = x - rhs.x;
	result.y = y - rhs.y;
	result.z = z - rhs.z;

	return result;
}

// Divide
Vector3 Vector3::operator/(const float rhs)
{
	Vector3 result;
	result.x = x / rhs;
	result.y = y / rhs;
	result.z = z / rhs;

	return result;
}

// Multiply vector by float
Vector3 Vector3::operator*(const float rhs)
{
	Vector3 result;
	result.x = x * rhs;
	result.y = y * rhs;
	result.z = z * rhs;

	return result;
}

// Multiply float by vector ( out side of class so we can order )
Vector3 operator*(float lhs, const Vector3& rhs)
{
	Vector3 result;
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;

	return result;
}

// Dot product
float Vector3::dot(const Vector3& rhs)
{
	float result;
	result = x * rhs.x + y * rhs.y + z * rhs.z;
	return result;
}

// Cross product
Vector3 Vector3::cross(const Vector3& rhs)
{
	Vector3 result;
	result.x = y * rhs.z - z * rhs.y;
	result.y = z * rhs.x - x * rhs.z;
	result.z = x * rhs.y - y * rhs.x;

	return result;
}

// Magnititude
float Vector3::magnitude()
{
	float result;
	result = sqrtf(x*x + y*y + z*z);
	return result;
}

// Magnititude Squared
float Vector3::MagnititudeSquared()
{
	float result;
	result = x*x + y*y + z*z;
	return result;
}

// Normalise
void Vector3::normalise()
{
	float mag = magnitude();

	if (mag != 0)
	{
		x = x / mag;
		y = y / mag;
		z = z / mag;
	}
}

// Normalised
Vector3 Vector3::Normalised(Vector3 data)
{
	float mag = data.magnitude();

	Vector3 result;

	if (mag != 0)
	{
		result.x = data.x / mag;
		result.y = data.y / mag;
		result.z = data.z / mag;

		return result;
	}
}

// Allow negative vector
Vector3 Vector3::operator-()
{
	Vector3 result;
	result.x = -x;
	result.y = -y;
	result.z = -z;

	return result;
}

// Greater then operator
bool Vector3::operator>(const Vector3 rhs)
{
	return (x > rhs.x && y > rhs.y && z > rhs.z);
}

// Less then operator
bool Vector3::operator<(const Vector3 rhs)
{
	return (x < rhs.x && y < rhs.y && z < rhs.z);

}

// Override plus equels
Vector3 Vector3::operator+=(const Vector3& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;

	return *this;
}

// Override minus equels
Vector3 Vector3::operator-=(const Vector3& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;

	return *this;
}

// Override multiply equels
Vector3 Vector3::operator*=(const float rhs)
{
	Vector3 result;
	result.x = x *= rhs;
	result.y = y *= rhs;
	result.z = z *= rhs;

	return result;
}

// Override divide equels
Vector3 Vector3::operator/=(const float rhs)
{
	Vector3 result;
	result.x = x /= rhs;
	result.y = y /= rhs;
	result.z = z /= rhs;

	return result;
}

// Sub-script operator returning a reference 
float& Vector3::operator[](const int rhs)
{
	if (rhs == 0)
		return x;
	else if (rhs == 1)
		return y;
	else if (rhs == 2)
		return z;
	else
		return x;
}

// Cast operator to float pointer
Vector3::operator float*()
{
	return &x;
}
