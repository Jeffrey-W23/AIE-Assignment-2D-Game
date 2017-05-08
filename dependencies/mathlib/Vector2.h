// #include, using, etc
#pragma once
#include "math.h"

// Preprogramming to check and then switch between if the program is a dll libary or static.
#ifdef STATIC_LIB
	#define MATH_DLL
#else
	#ifdef DLL_EXPORT
		#define MATH_DLL __declspec(dllexport)
	#else
		#define MATH_DLL __declspec(dllimport)
	#endif
#endif

//--------------------------------------------------------------------------------------
// Vector2 object
//--------------------------------------------------------------------------------------
class Vector2
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2();

	//--------------------------------------------------------------------------------------
	// Constructor for passing in two floats.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2(float x, float y);
	
	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	MATH_DLL ~Vector2();

	//--------------------------------------------------------------------------------------
	// Addition: Overloads the "+" operator so that Vector2s can be added together.
	//
	// Param:
	//		rhs: The right hand side value being passed into the function that you want added.
	// Return:
	//		Returns a Vector2 value equel to the values you added together.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator+(const Vector2& rhs);

	//--------------------------------------------------------------------------------------
	// Subtraction: Overloads the "-" operator so that Vector2s can be subtracted from each other.
	//
	// Param:
	//		rhs: The right hand side value being passed into the function that you want subtract.
	// Return:
	//		Returns a Vector2 value equel to the values you subtract together.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator-(const Vector2& rhs);

	//--------------------------------------------------------------------------------------
	// Divide: Overloads the "/" operator so that Vector2s can be Divided together.
	//
	// Param:
	//		rhs: The right hand side value being passed into the function that you want Divide.
	// Return:
	//		Returns a Vector2 value equel to the values you Divide together.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator/(const float rhs);

	//--------------------------------------------------------------------------------------
	// Multiply vector by float: Overloads the "*" operator so that Vector2s can be Multiplied by floats.
	//
	// Param:
	//		rhs: The float you would like to be multiplied by the vector
	// Return:
	//		Returns a Vector2 value equel to the values you Multiplied by.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator*(const float rhs);

	//--------------------------------------------------------------------------------------
	// Allow negative vectors: overload the "-" operator to also allow negative vectors.
	//
	// Return:
	//		Returns a negative Vector2.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator-();

	//--------------------------------------------------------------------------------------
	// Greater then operator: Overloads the ">" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector to be checked against.
	// Return:
	//		Returns a bool of true or false for if the value is greater then or not.
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator>(const Vector2 rhs);

	// --------------------------------------------------------------------------------------
	// Less then operator: Overloads the "<" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector to be checked against.
	// Return:
	//		Returns a bool of true or false for if the value is less then or not.
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator<(const Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Plus equal: Overloads the "+=" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector you would like to increase incremently.
	// Return:
	//		Returns a Vector2.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator+=(const Vector2& rhs);

	//--------------------------------------------------------------------------------------
	// Subtract equal: Overloads the "-=" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector you would like to decrease incremently.
	// Return:
	//		Returns a Vector2.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator-=(const Vector2& rhs);

	//--------------------------------------------------------------------------------------
	// Multiply equal: Overloads the "*=" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector you would like to decrease incremently.
	// Return:
	//		Returns a Vector2.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator*=(const float rhs);

	//--------------------------------------------------------------------------------------
	// Divide equal: Overloads the "/=" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector you would like to Divide incremently.
	// Return:
	//		Returns a Vector2.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator/=(const float rhs);

	//--------------------------------------------------------------------------------------
	// Sub-script operator returning a reference
	//
	// Param:
	//		rhs: takes in an int.
	// Return:
	//		Returns a float.
	//--------------------------------------------------------------------------------------
	MATH_DLL float& operator[](const int rhs);

	//--------------------------------------------------------------------------------------
	// Cast operator to float pointer
	//--------------------------------------------------------------------------------------
	MATH_DLL operator float*();

	//--------------------------------------------------------------------------------------
	// Equal to operator: Overloads the "==" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector to be checked against.
	// Return:
	//		Returns a bool of true or false for if the value is equal to or not.
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator==(const Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Not Equal to operator: Overloads the "!=" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector to be checked against.
	// Return:
	//		Returns a bool of true or false for if the value is equal to or not.
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator!=(const Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Greater then or equal to operator: Overloads the ">=" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector to be checked against.
	// Return:
	//		Returns a bool of true or false for if the value is greater then or equal to or not.
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator>=(const Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Less then or equal to operator: Overloads the "<=" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector to be checked against.
	// Return:
	//		Returns a bool of true or false for if the value is less then or equal or not.
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator<=(const Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Dot Product: Dot Product of two vectors.
	//
	// Param:
	//		rhs: Vector2 you want the dot product of.
	// Return:
	//		Returns a float value of the dot product of the vector.
	//--------------------------------------------------------------------------------------
	MATH_DLL float dot(const Vector2& rhs);

	//--------------------------------------------------------------------------------------
	// Magnitude: Returns the length of this vector.
	//
	// Return:
	//		Returns a float that is the length of the vector.
	//--------------------------------------------------------------------------------------
	MATH_DLL float magnitude();

	//--------------------------------------------------------------------------------------
	// MagnititudeSquared: Returns the squared length of this vector
	//
	// Return:
	//		Returns a float that is the length of the vector.
	//--------------------------------------------------------------------------------------
	MATH_DLL float MagnititudeSquared();

	//--------------------------------------------------------------------------------------
	// Normalise: Makes this vector have a magnitude of 1. (It keeps the same direction)
	// This function will change the current vector.
	//--------------------------------------------------------------------------------------
	MATH_DLL void normalise();

	//--------------------------------------------------------------------------------------
	// Normalised: Makes this vector have a magnitude of 1. (It keeps the same direction) 
	// This function will not change the current vector and a new one will be created.
	//
	// Param:
	//		data: A Vector2 to be normalised.
	// Return:
	//		Returns a Vector2 of the normalised value.
	//--------------------------------------------------------------------------------------
	MATH_DLL static Vector2 Normalised(Vector2 data);

	//--------------------------------------------------------------------------------------
	// CalcNormal: Calculate the normal of a face.
	//
	// Param:
	//		pos: Vector2 position.
	// Return:
	//		Returns a Vector2 value that is the normal of a face.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 CalcNormal(Vector2 pos);

	//--------------------------------------------------------------------------------------
	// Min: Returns a vector that is made from the smallest components of two vectors.
	//
	// Param:
	//		rhs: The second vector to compare to.
	// Return:
	//		Returns a Vector2 that is the smallest components of two vectors.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 Min(Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Max: Returns a vector that is made from the largest components of two vectors.
	//
	// Param:
	//		rhs: The second vector to compare to.
	// Return:
	//		Returns a Vector2 that is the largest components of two vectors.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 Max(Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Clamp: Stop a vector at a max length.
	//
	// Param:
	//		min: The minimum of the vector.
	//		max: The maximum of the vector.
	// Return:
	//		Returns a Vector2 clamped at the maxlength.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 Clamp(Vector2 min, Vector2 max);

	//--------------------------------------------------------------------------------------
	// Lerp: Linearly interpolates between vectors a and b by t.
	//
	// Param:
	//		a: Vector2
	//		b: Vector2
	//		t: Float 
	// Return:
	//		Returns a Vector2 
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 Lerp(Vector2 a, Vector2 b, float t);

	//--------------------------------------------------------------------------------------
	// Distance: Returns the distance between a and b.
	//
	// Param:
	//		a: Vector2
	//		b: Vector2
	// Return:
	//		Returns a float which is the distance between a and b.
	//--------------------------------------------------------------------------------------
	MATH_DLL float Distance(Vector2 pos1, Vector2 pos2);

	//--------------------------------------------------------------------------------------
	// Bezier: A function to calculate a bezier curves.
	//
	// Param:
	//		t: A float representing time.
	//		a: Vector2 point.
	//		b: Vector2 point.
	//		c: Vector2 point.
	// Return:
	//		Returns a Vector2 value of the Bezier curve.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 Bezier(float t, Vector2 a, Vector2 b, Vector2 c);

	//--------------------------------------------------------------------------------------
	// hermiteCurve: A function to calculate a hermite Curve.
	//
	// Param:
	//		point0: Vector2 point.
	//		tangent0: Vector2 tangent.
	//		point1: Vector2 point.
	//		tangent1: Vector2 tangent.
	//		t: A float representing time.
	// Return:
	//		Returns a Vector2 value of the hermite curve.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 hermiteCurve(Vector2 point0, Vector2 tangent0, Vector2 point1, Vector2 tangent1, float t);

	//--------------------------------------------------------------------------------------
	// Swizzle: Switch around the values of x and y to every possible combo.
	//
	// Return:
	//		Returns a Vector2 value with the applied changes.
	//--------------------------------------------------------------------------------------
	//////////////// SWIZZLE ////////////////
	// Swizzle for xx
	MATH_DLL Vector2 xx();

	// Swizzle for xy
	MATH_DLL Vector2 xy();

	// Swizzle for yx
	MATH_DLL Vector2 yx();

	// Swizzle for yy
	MATH_DLL Vector2 yy();
	//////////////// SWIZZLE ////////////////

	//--------------------------------------------------------------------------------------
	// Union creating the x and y for the vector class. Using a union so we can have both floats and an array of floats
	//--------------------------------------------------------------------------------------
	union
	{
		// Structs act as one in a union
		struct
		{
			float x;
			float y;
		};

		float vec[2];
	};
};

//--------------------------------------------------------------------------------------
// Multiply float by vector: Overloads the "*" operator so that floats can be Multiplied by Vector2s.
//
// Param:
//		lhs: The float you would like to multiply by the Vector2.
//		rhs: The Vector2 you would like to be multiplied by the float.
// Return:
//		Returns a Vector2 value equel to the values you Multiplied by.
//
// (out side of class so we can order)
//--------------------------------------------------------------------------------------
MATH_DLL Vector2 operator*(float lhs, const Vector2& rhs);