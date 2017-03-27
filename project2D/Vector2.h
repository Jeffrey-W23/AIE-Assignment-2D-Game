// #include, using, etc
#pragma once

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

	// Multiply vector by float
	Vector2 operator*(const float rhs);
	
	// Dot product
	float Dot(Vector2 rhs);

	// Allow negative vector
	Vector2 operator-();

	// declare public floats for x and y
	float x;
	float y;
};

// Float multiplyed by vector ( out side of class so we can order )
Vector2 operator*(float lhs, const Vector2& rhs);



// BONUS
// make sure to do dev
// do plus equels
// do minus equels
// do times equels
// do dev equels

// how do I overload this operator c++