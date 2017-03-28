// #include, using, etc
#pragma once
#include "math.h"

// Vector2 object
class Vector3
{
public:

	// Default Constructor
	Vector3();

	// Constructor passing in 2 floats
	Vector3(float x, float y, float z);

	// Default Destructor
	~Vector3();

	// Addition
	Vector3 operator+(const Vector3& rhs);

	// Subtraction
	Vector3 operator-(const Vector3& rhs);

	// Divide
	Vector3 operator/(const float rhs);

	// Multiply vector by float
	Vector3 operator*(const float rhs);

	// Dot product
	float DotProduct(const Vector3& rhs);

	// cross product
	Vector3 CrossProduct(const Vector3& rhs);

	// Magnititude
	float Magnititude();

	// Magnititude Squared
	float MagnititudeSquared();

	// Normalise
	void Normalise();

	// Allow negative vector
	Vector3 operator-();

	// Greater then operator
	bool operator>(const Vector3 rhs);

	// Less then operator
	bool operator<(const Vector3 rhs);

	// plus equels
	Vector3 operator+=(const Vector3& rhs);

	// minus equels
	Vector3 operator-=(const Vector3& rhs);

	// Multiply equels
	Vector3 operator*=(const float rhs);

	// Divide equels
	Vector3 operator/=(const float rhs);

	// declare public floats for x and y
	float x;
	float y;
	float z;
};

// Float multiplyed by vector ( out side of class so we can order )
Vector3 operator*(float lhs, const Vector3& rhs);