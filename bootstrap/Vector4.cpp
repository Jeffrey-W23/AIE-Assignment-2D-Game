// #include, using, etc
#include "Vector4.h"

// Default Constructor
Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 1;
}

// Constructor passing in 2 floats
Vector4::Vector4(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

// Default Destructor
Vector4::~Vector4()
{
}

// Addition
Vector4 Vector4::operator+(const Vector4& rhs)
{
	Vector4 result;
	result.x = x + rhs.x;
	result.y = y + rhs.y;
	result.z = z + rhs.z;
	result.w = w + rhs.w;

	return result;
}

// Subtraction
Vector4 Vector4::operator-(const Vector4& rhs)
{
	Vector4 result;
	result.x = x - rhs.x;
	result.y = y - rhs.y;
	result.z = z - rhs.z;
	result.w = w - rhs.w;

	return result;
}

// Divide
Vector4 Vector4::operator/(const float rhs)
{
	Vector4 result;
	result.x = x / rhs;
	result.y = y / rhs;
	result.z = z / rhs;
	result.w = w / rhs;

	return result;
}

// Multiply vector by float
Vector4 Vector4::operator*(const float rhs)
{
	Vector4 result;
	result.x = x * rhs;
	result.y = y * rhs;
	result.z = z * rhs;
	result.w = w * rhs;

	return result;
}

// Multiply float by vector ( out side of class so we can order )
Vector4 operator*(float lhs, const Vector4& rhs)
{
	Vector4 result;
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;
	result.w = lhs * rhs.w;

	return result;
}

// Dot product
float Vector4::DotProduct(const Vector4& rhs)
{
	float result;
	result = x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
	return result;
}

// Cross product
Vector4 Vector4::CrossProduct(const Vector4& rhs)
{
	Vector4 result;
	result.x = y * rhs.z - z * rhs.y;
	result.y = z * rhs.x - x * rhs.z;
	result.z = x * rhs.y - y * rhs.x;
	result.w = 0;

	return result;
}

// Magnititude
float Vector4::Magnititude()
{
	float result;
	result = sqrtf(x*x + y*y + z*z + w*w);
	return result;
}

// Magnititude Squared
float Vector4::MagnititudeSquared()
{
	float result;
	result = x*x + y*y + z*z + w*w;
	return result;
}

// Normalise
void Vector4::Normalise()
{
	float mag = Magnititude();

	if (mag != 0)
	{
		x = x / mag;
		y = y / mag;
		z = z / mag;
		w = w / mag;
	}
}

// Normalised
Vector4 Vector4::Normalised(Vector4 data)
{
	float mag = data.Magnititude();

	Vector4 result;

	if (mag != 0)
	{
		result.x = data.x / mag;
		result.y = data.y / mag;
		result.z = data.z / mag;
		result.w = data.w / mag;

		return result;
	}
}

// Allow negative vector
Vector4 Vector4::operator-()
{
	Vector4 result;
	result.x = -x;
	result.y = -y;
	result.z = -z;
	result.w = -w;

	return result;
}

// Greater then operator
bool Vector4::operator>(const Vector4 rhs)
{
	return (x > rhs.x && y > rhs.y && z > rhs.z && w > rhs.w);
}

// Less then operator
bool Vector4::operator<(const Vector4 rhs)
{
	return (x < rhs.x && y < rhs.y && z < rhs.z && w < rhs.w);

}

// Override plus equels
Vector4 Vector4::operator+=(const Vector4& rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	w += rhs.w;

	return *this;
}

// Override minus equels
Vector4 Vector4::operator-=(const Vector4& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	w -= rhs.w;

	return *this;
}

// Override multiply equels
Vector4 Vector4::operator*=(const float rhs)
{
	Vector4 result;
	result.x = x *= rhs;
	result.y = y *= rhs;
	result.z = z *= rhs;
	result.w = w *= rhs;

	return result;
}

// Override divide equels
Vector4 Vector4::operator/=(const float rhs)
{
	Vector4 result;
	result.x = x /= rhs;
	result.y = y /= rhs;
	result.z = z /= rhs;
	result.w = w /= rhs;

	return result;
}
