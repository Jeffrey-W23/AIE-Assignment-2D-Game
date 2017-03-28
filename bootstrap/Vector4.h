// #include, using, etc
#pragma once
#include "math.h"

// Vector2 object
class Vector4
{
public:

	// Default Constructor
	Vector4();

	// Constructor passing in 2 floats
	Vector4(float x, float y, float z, float w);

	// Default Destructor
	~Vector4();

	// Addition
	Vector4 operator+(const Vector4& rhs);

	// Subtraction
	Vector4 operator-(const Vector4& rhs);

	// Divide
	Vector4 operator/(const float rhs);

	// Multiply vector by float
	Vector4 operator*(const float rhs);

	// Dot product
	float DotProduct(const Vector4& rhs);

	// cross product
	Vector4 CrossProduct(const Vector4& rhs);

	// Magnititude
	float Magnititude();

	// Magnititude Squared
	float MagnititudeSquared();

	// Normalise
	void Normalise();

	// Allow negative vector
	Vector4 operator-();

	// Greater then operator
	bool operator>(const Vector4 rhs);

	// Less then operator
	bool operator<(const Vector4 rhs);

	// plus equels
	Vector4 operator+=(const Vector4& rhs);

	// minus equels
	Vector4 operator-=(const Vector4& rhs);

	// Multiply equels
	Vector4 operator*=(const float rhs);

	// Divide equels
	Vector4 operator/=(const float rhs);

	// declare public floats for x and y
	float x;
	float y;
	float z;
	float w;
};

// Float multiplyed by vector ( out side of class so we can order )
Vector4 operator*(float lhs, const Vector4& rhs);