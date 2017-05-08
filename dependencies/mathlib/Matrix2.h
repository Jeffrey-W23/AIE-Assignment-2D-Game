// #include, using, etc
#pragma once
#include "Vector2.h"

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
// Matrix2 object
//--------------------------------------------------------------------------------------
class Matrix2
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix2();

	//--------------------------------------------------------------------------------------
	// Constructor for passing in four floats.
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix2(float Xx, float Xy, float Yx, float Yy);
	
	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	MATH_DLL ~Matrix2();

	//--------------------------------------------------------------------------------------
	// Multiply: Overloads the "*" operator so that you can multiply a Matrix by a Vector
	//
	// Param:
	//		rhs: The right hand side value being passed into the function that you want multiplied.
	// Return:
	//		Returns a Vector2 of the result.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator*(const Vector2& rhs);
	
	//--------------------------------------------------------------------------------------
	// Multiply: Overloads the "*" operator so that you can multiply two Matrix toegther.
	//
	// Param:
	//		rhs: The right hand side value being passed into the function that you want multiplied.
	// Return:
	//		Returns a Matrix2 value of the result.
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix2 operator*(const Matrix2& rhs);

	//--------------------------------------------------------------------------------------
	// Sub-script operator returning a reference
	//
	// Param:
	//		rhs: takes in an int.
	// Return:
	//		Returns a Vector2.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2& operator[](const int rhs);

	//--------------------------------------------------------------------------------------
	// Cast operator to float pointer
	//--------------------------------------------------------------------------------------
	MATH_DLL operator float*();

	//--------------------------------------------------------------------------------------
	// Set Rotation for the matrix
	//
	// Param:
	//		a: float to rotate by.
	//--------------------------------------------------------------------------------------
	MATH_DLL void setRotate(const float a);

	//--------------------------------------------------------------------------------------
	// Set Scale: set the scale of the matrix
	//
	// Param:
	//		x: float for the x axis
	//		y: float for the y axis
	//--------------------------------------------------------------------------------------
	MATH_DLL void setScale(const float x, const float y);

	//--------------------------------------------------------------------------------------
	// Get Scale
	//
	// Return:
	//		Returns a Vector2 of the scale of the matrix
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 getScale();

	//--------------------------------------------------------------------------------------
	// Determinant: The determinant of the matrix.
	//
	// Return:
	//		Returns a float
	//--------------------------------------------------------------------------------------
	MATH_DLL float Determinant();

	//--------------------------------------------------------------------------------------
	// isIdentity: Check which one the Identity matrix is.
	//
	// Return:
	//		Returns a bool true or false if it is the identity matrix or not.
	//--------------------------------------------------------------------------------------
	MATH_DLL bool isIdentity();

	//--------------------------------------------------------------------------------------
	// Transpose: get the transpose of this matrix.
	//--------------------------------------------------------------------------------------
	MATH_DLL void Transpose();

	//--------------------------------------------------------------------------------------
	// Union creating matrix. Using a union so we can have both single array and double array.
	//--------------------------------------------------------------------------------------
	union
	{
		float m[4];
		float a[2][2];
	};
};