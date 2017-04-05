// #include, using, etc
#pragma once
#include "math.h"

// Vector2 object
class Vector2
{
public:

	// Default Constructor
	Vector2();

	// Constructor passing in 2 floats
	Vector2(float x, float y);
	
	// Default Destructor
	~Vector2();

	// Addition
	Vector2 operator+(const Vector2& rhs);

	// Subtraction
	Vector2 operator-(const Vector2& rhs);

	// Divide
	Vector2 operator/(const float rhs);

	// Multiply vector by float
	Vector2 operator*(const float rhs);
	
	// Dot product
	float dot(const Vector2& rhs);

	// Magnititude
	float magnitude();

	// Magnititude Squared
	float MagnititudeSquared();

	// Normalise
	void normalise();

	// Normalised
	static Vector2 Normalised(Vector2 data);

	// Allow negative vector
	Vector2 operator-();

	// Greater then operator
	bool operator>(const Vector2 rhs);

	// Less then operator
	bool operator<(const Vector2 rhs);

	// plus equels
	Vector2 operator+=(const Vector2& rhs);
	
	// minus equels
	Vector2 operator-=(const Vector2& rhs);
	
	// Multiply equels
	Vector2 operator*=(const float rhs);
	
	// Divide equels
	Vector2 operator/=(const float rhs);

	// Sub-script operator returning a reference 
	float& operator[](const int rhs);

	// Cast operator to float pointer
	operator float*();

	// declare public floats for x and y
	float x;
	float y;
};

// Float multiplyed by vector ( out side of class so we can order )
Vector2 operator*(float lhs, const Vector2& rhs);