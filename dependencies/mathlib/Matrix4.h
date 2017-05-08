// #include, using, etc
#pragma once
#include "Vector4.h"
#include "Vector3.h"

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
// Matrix4 object
//--------------------------------------------------------------------------------------
class Matrix4
{
public:
	
	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix4();
	
	//--------------------------------------------------------------------------------------
	// Constructor for passing in 16 floats.
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix4(float Xx, float Xy, float Xz, float Xw, float Yx, float Yy, float Yz, float Yw, float Zx, float Zy, float Zz, float Zw, float Tx, float Ty, float Tz, float Tw);
	
	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	MATH_DLL ~Matrix4();

	//--------------------------------------------------------------------------------------
	// Multiply: Overloads the "*" operator so that you can multiply a Matrix by a Vector
	//
	// Param:
	//		rhs: The right hand side value being passed into the function that you want multiplied.
	// Return:
	//		Returns a Vector4 of the result.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 operator*(const Vector4& rhs);

	//--------------------------------------------------------------------------------------
	// Multiply: Overloads the "*" operator so that you can multiply two Matrix toegther.
	//
	// Param:
	//		rhs: The right hand side value being passed into the function that you want multiplied.
	// Return:
	//		Returns a Matrix4 value of the result.
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix4 operator*(const Matrix4& rhs);

	//--------------------------------------------------------------------------------------
	// Sub-script operator returning a reference
	//
	// Param:
	//		rhs: takes in an int.
	// Return:
	//		Returns a Vector4.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4& operator[](const int rhs);

	//--------------------------------------------------------------------------------------
	// Cast operator to float pointer
	//--------------------------------------------------------------------------------------
	MATH_DLL operator float*();

	//--------------------------------------------------------------------------------------
	// Set Rotation X for the matrix
	//
	// Param:
	//		a: float to rotate by.
	//--------------------------------------------------------------------------------------
	MATH_DLL void setRotateX(const float a);

	//--------------------------------------------------------------------------------------
	// Set Rotation Y for the matrix
	//
	// Param:
	//		a: float to rotate by.
	//--------------------------------------------------------------------------------------
	MATH_DLL void setRotateY(const float a);

	//--------------------------------------------------------------------------------------
	// Set Rotation Z for the matrix
	//
	// Param:
	//		a: float to rotate by.
	//--------------------------------------------------------------------------------------
	MATH_DLL void setRotateZ(const float a);

	//--------------------------------------------------------------------------------------
	// Set Scale: set the scale of the matrix
	//
	// Param:
	//		x: float for the x axis
	//		y: float for the y axis
	//--------------------------------------------------------------------------------------
	MATH_DLL void setScale(const float x, const float y, const float z, const float w);

	//--------------------------------------------------------------------------------------
	// Get Scale
	//
	// Return:
	//		Returns a Vector4 of the scale of the matrix
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 getScale();

	//--------------------------------------------------------------------------------------
	// Set Postion Vector: Set position with a vector.
	//
	// Param:
	//		rhs: Vector for postion value.
	//--------------------------------------------------------------------------------------
	MATH_DLL void setPostionv(const Vector3& rhs);

	//--------------------------------------------------------------------------------------
	// Set Postion float: Set position with a float.
	//
	// Param:
	//		x: float for x axis
	//		y: float for y axis
	//		z: float for z axis
	//--------------------------------------------------------------------------------------
	MATH_DLL void setPostionf(const float x, const float y, const float z);

	//--------------------------------------------------------------------------------------
	// Get Postion
	//
	// Return:
	//		Returns a Vector4.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 getPos();

	//--------------------------------------------------------------------------------------
	// Look At: Gets a matrix that corresponds to a camera viewing a target.
	//
	// Param:
	//		from: Vector3
	//		target: Vector3
	//		up: Vector 3
	//--------------------------------------------------------------------------------------
	MATH_DLL void LookAt(Vector3 from, const Vector3 target, const Vector3 up);

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
		float m[16];
		float a[4][4];
	};
};

