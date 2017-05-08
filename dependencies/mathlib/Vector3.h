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
// Vector3 object
//--------------------------------------------------------------------------------------
class Vector3
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3();

	//--------------------------------------------------------------------------------------
	// Constructor for passing in three floats.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3(float x, float y, float z);

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	MATH_DLL ~Vector3();

	//--------------------------------------------------------------------------------------
	// Addition: Overloads the "+" operator so that Vector3 can be added together.
	//
	// Param:
	//		rhs: The right hand side value being passed into the function that you want added.
	// Return:
	//		Returns a Vector3 value equel to the values you added together.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 operator+(const Vector3& rhs);

	//--------------------------------------------------------------------------------------
	// Subtraction: Overloads the "-" operator so that Vector3s can be subtracted from each other.
	//
	// Param:
	//		rhs: The right hand side value being passed into the function that you want subtract.
	// Return:
	//		Returns a Vector3 value equel to the values you subtract together.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 operator-(const Vector3& rhs);

	//--------------------------------------------------------------------------------------
	// Divide: Overloads the "/" operator so that Vector3s can be Divided together.
	//
	// Param:
	//		rhs: The right hand side value being passed into the function that you want Divide.
	// Return:
	//		Returns a Vector3 value equel to the values you Divide together.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 operator/(const float rhs);

	//--------------------------------------------------------------------------------------
	// Multiply vector by float: Overloads the "*" operator so that Vector3s can be Multiplied by floats.
	//
	// Param:
	//		rhs: The float you would like to be multiplied by the vector
	// Return:
	//		Returns a Vector3 value equel to the values you Multiplied by.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 operator*(const float rhs);

	//--------------------------------------------------------------------------------------
	// Allow negative vectors: overload the "-" operator to also allow negative vectors.
	//
	// Return:
	//		Returns a negative Vector3.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 operator-();

	//--------------------------------------------------------------------------------------
	// Greater then operator: Overloads the ">" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector to be checked against.
	// Return:
	//		Returns a bool of true or false for if the value is greater then or not.
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator>(const Vector3 rhs);

	// --------------------------------------------------------------------------------------
	// Less then operator: Overloads the "<" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector to be checked against.
	// Return:
	//		Returns a bool of true or false for if the value is less then or not.
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator<(const Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Plus equal: Overloads the "+=" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector you would like to increase incremently.
	// Return:
	//		Returns a Vector3.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 operator+=(const Vector3& rhs);

	//--------------------------------------------------------------------------------------
	// Subtract equal: Overloads the "-=" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector you would like to decrease incremently.
	// Return:
	//		Returns a Vector3.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 operator-=(const Vector3& rhs);

	//--------------------------------------------------------------------------------------
	// Multiply equal: Overloads the "*=" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector you would like to decrease incremently.
	// Return:
	//		Returns a Vector3.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 operator*=(const float rhs);

	//--------------------------------------------------------------------------------------
	// Divide equal: Overloads the "/=" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector you would like to Divide incremently.
	// Return:
	//		Returns a Vector3.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 operator/=(const float rhs);

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
	MATH_DLL bool operator==(const Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Not Equal to operator: Overloads the "!=" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector to be checked against.
	// Return:
	//		Returns a bool of true or false for if the value is equal to or not.
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator!=(const Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Greater then or equal to operator: Overloads the ">=" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector to be checked against.
	// Return:
	//		Returns a bool of true or false for if the value is greater then or equal to or not.
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator>=(const Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Less then or equal to operator: Overloads the "<=" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector to be checked against.
	// Return:
	//		Returns a bool of true or false for if the value is less then or equal or not.
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator<=(const Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Dot Product: Dot Product of two vectors.
	//
	// Param:
	//		rhs: Vector3 you want the dot product of.
	// Return:
	//		Returns a float value of the dot product of the vector.
	//--------------------------------------------------------------------------------------
	MATH_DLL float dot(const Vector3& rhs);

	//--------------------------------------------------------------------------------------
	// Cross: Cross Product of two vectors is another Vector.
	//
	// Param:
	//		rhs: Vector3 to do the corss product on.
	// Return:
	//		Returns a Vector3 value that is the new Vector.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 cross(const Vector3& rhs);

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
	//		data: A Vector3 to be normalised.
	// Return:
	//		Returns a Vector3 of the normalised value.
	//--------------------------------------------------------------------------------------
	MATH_DLL static Vector3 Normalised(Vector3 data);

	//--------------------------------------------------------------------------------------
	// CalcNormal: Calculate the normal of a face.
	//
	// Param:
	//		pos: Vector3 position.
	// Return:
	//		Returns a Vector3 value that is the normal of a face.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 CalcNormal(Vector3 pos1, Vector3 pos2);

	//--------------------------------------------------------------------------------------
	// Min: Returns a vector that is made from the smallest components of two vectors.
	//
	// Param:
	//		rhs: The second vector to compare to.
	// Return:
	//		Returns a Vector3 that is the smallest components of two vectors.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 Min(Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Max: Returns a vector that is made from the largest components of two vectors.
	//
	// Param:
	//		rhs: The second vector to compare to.
	// Return:
	//		Returns a Vector3 that is the largest components of two vectors.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 Max(Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Clamp: Stop a vector at a max length.
	//
	// Param:
	//		min: The minimum of the vector.
	//		max: The maximum of the vector.
	// Return:
	//		Returns a Vector3 clamped at the maxlength.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 Clamp(Vector3 min, Vector3 max);

	//--------------------------------------------------------------------------------------
	// Lerp: Linearly interpolates between vectors a and b by t.
	//
	// Param:
	//		a: Vector3
	//		b: Vector3
	//		t: Float 
	// Return:
	//		Returns a Vector3 
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 Lerp(Vector3 a, Vector3 b, float t);

	//--------------------------------------------------------------------------------------
	// Distance: Returns the distance between a and b.
	//
	// Param:
	//		a: Vector3
	//		b: Vector3
	// Return:
	//		Returns a float which is the distance between a and b.
	//--------------------------------------------------------------------------------------
	MATH_DLL float Distance(Vector3 pos1, Vector3 pos2);

	//--------------------------------------------------------------------------------------
	// Bezier: A function to calculate a bezier curves.
	//
	// Param:
	//		t: A float representing time.
	//		a: Vector3 point.
	//		b: Vector3 point.
	//		c: Vector3 point.
	// Return:
	//		Returns a Vector3 value of the Bezier curve.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 Bezier(float t, Vector3 a, Vector3 b, Vector3 c);

	//--------------------------------------------------------------------------------------
	// hermiteCurve: A function to calculate a hermite Curve.
	//
	// Param:
	//		point0: Vector3 point.
	//		tangent0: Vector3 tangent.
	//		point1: Vector3 point.
	//		tangent1: Vector3 tangent.
	//		t: A float representing time.
	// Return:
	//		Returns a Vector3 value of the hermite curve.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 hermiteCurve(Vector3 point0, Vector3 tangent0, Vector3 point1, Vector3 tangent1, float t);

	//--------------------------------------------------------------------------------------
	// Swizzle: Switch around the values of x, y and z to every possible combo.
	//
	// Return:
	//		Returns a Vector3 value with the applied changes.
	//--------------------------------------------------------------------------------------
	//////////////// SWIZZLE ////////////////
	// Swizzle for xxx
	MATH_DLL Vector3 xxx();

	// Swizzle for xxy
	MATH_DLL Vector3 xxy();

	// Swizzle for xxz
	MATH_DLL Vector3 xxz();

	// Swizzle for xyx
	MATH_DLL Vector3 xyx();

	// Swizzle for xyy
	MATH_DLL Vector3 xyy();

	// Swizzle for xyz
	MATH_DLL Vector3 xyz();

	// Swizzle for xzx
	MATH_DLL Vector3 xzx();

	// Swizzle for xzy
	MATH_DLL Vector3 xzy();

	// Swizzle for xzz
	MATH_DLL Vector3 xzz();

	// Swizzle for yxx
	MATH_DLL Vector3 yxx();

	// Swizzle for yxy
	MATH_DLL Vector3 yxy();

	// Swizzle for yxz
	MATH_DLL Vector3 yxz();

	// Swizzle for yyx
	MATH_DLL Vector3 yyx();

	// Swizzle for yyy
	MATH_DLL Vector3 yyy();

	// Swizzle for yyz
	MATH_DLL Vector3 yyz();

	// Swizzle for yzx
	MATH_DLL Vector3 yzx();

	// Swizzle for yzy
	MATH_DLL Vector3 yzy();

	// Swizzle for yzz
	MATH_DLL Vector3 yzz();

	// Swizzle for zxx
	MATH_DLL Vector3 zxx();

	// Swizzle for zxy
	MATH_DLL Vector3 zxy();

	// Swizzle for zxz
	MATH_DLL Vector3 zxz();

	// Swizzle for zyx
	MATH_DLL Vector3 zyx();

	// Swizzle for zyy
	MATH_DLL Vector3 zyy();

	// Swizzle for zyz
	MATH_DLL Vector3 zyz();

	// Swizzle for zzx
	MATH_DLL Vector3 zzx();

	// Swizzle for zzy
	MATH_DLL Vector3 zzy();

	// Swizzle for zzz
	MATH_DLL Vector3 zzz();
	//////////////// SWIZZLE ////////////////

	//--------------------------------------------------------------------------------------
	// Union creating the x, y and z for the vector class. Using a union so we can have both floats and an array of floats
	//--------------------------------------------------------------------------------------
	union
	{
		struct
		{
			float x;
			float y;
			float z;
		};

		float vec[3];
	};
};

//--------------------------------------------------------------------------------------
// Multiply float by vector: Overloads the "*" operator so that floats can be Multiplied by Vector3s.
//
// Param:
//		lhs: The float you would like to multiply by the Vector3.
//		rhs: The Vector3 you would like to be multiplied by the float.
// Return:
//		Returns a Vector3 value equel to the values you Multiplied by.
//
// (out side of class so we can order)
//--------------------------------------------------------------------------------------
MATH_DLL Vector3 operator*(float lhs, const Vector3& rhs);