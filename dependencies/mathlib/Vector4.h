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
// Vector4 object
//--------------------------------------------------------------------------------------
class Vector4
{
public:

	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4();

	//--------------------------------------------------------------------------------------
	// Constructor for passing in four floats.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4(float x, float y, float z, float w);

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	MATH_DLL ~Vector4();

	//--------------------------------------------------------------------------------------
	// Addition: Overloads the "+" operator so that Vector4s can be added together.
	//
	// Param:
	//		rhs: The right hand side value being passed into the function that you want added.
	// Return:
	//		Returns a Vector4 value equel to the values you added together.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 operator+(const Vector4& rhs);

	//--------------------------------------------------------------------------------------
	// Subtraction: Overloads the "-" operator so that Vector4s can be subtracted from each other.
	//
	// Param:
	//		rhs: The right hand side value being passed into the function that you want subtract.
	// Return:
	//		Returns a Vector4 value equel to the values you subtract together.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 operator-(const Vector4& rhs);

	//--------------------------------------------------------------------------------------
	// Divide: Overloads the "/" operator so that Vector4s can be Divided together.
	//
	// Param:
	//		rhs: The right hand side value being passed into the function that you want Divide.
	// Return:
	//		Returns a Vector4 value equel to the values you Divide together.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 operator/(const float rhs);

	//--------------------------------------------------------------------------------------
	// Multiply vector by float: Overloads the "*" operator so that Vector4s can be Multiplied by floats.
	//
	// Param:
	//		rhs: The float you would like to be multiplied by the vector
	// Return:
	//		Returns a Vector4 value equel to the values you Multiplied by.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 operator*(const float rhs);

	//--------------------------------------------------------------------------------------
	// Allow negative vectors: overload the "-" operator to also allow negative vectors.
	//
	// Return:
	//		Returns a negative Vector4.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 operator-();

	//--------------------------------------------------------------------------------------
	// Greater then operator: Overloads the ">" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector to be checked against.
	// Return:
	//		Returns a bool of true or false for if the value is greater then or not.
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator>(const Vector4 rhs);

	// --------------------------------------------------------------------------------------
	// Less then operator: Overloads the "<" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector to be checked against.
	// Return:
	//		Returns a bool of true or false for if the value is less then or not.
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator<(const Vector4 rhs);

	//--------------------------------------------------------------------------------------
	// Plus equal: Overloads the "+=" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector you would like to increase incremently.
	// Return:
	//		Returns a Vector4.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 operator+=(const Vector4& rhs);

	//--------------------------------------------------------------------------------------
	// Subtract equal: Overloads the "-=" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector you would like to decrease incremently.
	// Return:
	//		Returns a Vector4.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 operator-=(const Vector4& rhs);

	//--------------------------------------------------------------------------------------
	// Multiply equal: Overloads the "*=" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector you would like to decrease incremently.
	// Return:
	//		Returns a Vector4.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 operator*=(const float rhs);

	//--------------------------------------------------------------------------------------
	// Divide equal: Overloads the "/=" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector you would like to Divide incremently.
	// Return:
	//		Returns a Vector4.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 operator/=(const float rhs);

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
	MATH_DLL bool operator==(const Vector4 rhs);

	//--------------------------------------------------------------------------------------
	// Not Equal to operator: Overloads the "!=" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector to be checked against.
	// Return:
	//		Returns a bool of true or false for if the value is equal to or not.
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator!=(const Vector4 rhs);

	//--------------------------------------------------------------------------------------
	// Greater then or equal to operator: Overloads the ">=" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector to be checked against.
	// Return:
	//		Returns a bool of true or false for if the value is greater then or equal to or not.
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator>=(const Vector4 rhs);

	//--------------------------------------------------------------------------------------
	// Less then or equal to operator: Overloads the "<=" operator so that it can be used with Vectors.
	//
	// Param:
	//		rhs: The Vector to be checked against.
	// Return:
	//		Returns a bool of true or false for if the value is less then or equal or not.
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator<=(const Vector4 rhs);

	//--------------------------------------------------------------------------------------
	// Dot Product: Dot Product of two vectors.
	//
	// Param:
	//		rhs: Vector4 you want the dot product of.
	// Return:
	//		Returns a float value of the dot product of the vector.
	//--------------------------------------------------------------------------------------
	MATH_DLL float dot(const Vector4& rhs);

	//--------------------------------------------------------------------------------------
	// Cross: Cross Product of two vectors is another Vector.
	//
	// Param:
	//		rhs: Vector4 to do the corss product on.
	// Return:
	//		Returns a Vector4 value that is the new Vector.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 cross(const Vector4& rhs);

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
	//		data: A Vector4 to be normalised.
	// Return:
	//		Returns a Vector4 of the normalised value.
	//--------------------------------------------------------------------------------------
	MATH_DLL static Vector4 Normalised(Vector4 data);

	//--------------------------------------------------------------------------------------
	// CalcNormal: Calculate the normal of a face.
	//
	// Param:
	//		pos: Vector4 position.
	// Return:
	//		Returns a Vector4 value that is the normal of a face.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 CalcNormal(Vector4 pos1, Vector4 pos2);

	//--------------------------------------------------------------------------------------
	// Min: Returns a vector that is made from the smallest components of two vectors.
	//
	// Param:
	//		rhs: The second vector to compare to.
	// Return:
	//		Returns a Vector4 that is the smallest components of two vectors.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 Min(Vector4 rhs);

	//--------------------------------------------------------------------------------------
	// Max: Returns a vector that is made from the largest components of two vectors.
	//
	// Param:
	//		rhs: The second vector to compare to.
	// Return:
	//		Returns a Vector4 that is the largest components of two vectors.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 Max(Vector4 rhs);

	//--------------------------------------------------------------------------------------
	// Clamp: Stop a vector at a max length.
	//
	// Param:
	//		min: The minimum of the vector.
	//		max: The maximum of the vector.
	// Return:
	//		Returns a Vector4 clamped at the maxlength.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 Clamp(Vector4 min, Vector4 max);

	//--------------------------------------------------------------------------------------
	// Lerp: Linearly interpolates between vectors a and b by t.
	//
	// Param:
	//		a: Vector4
	//		b: Vector4
	//		t: Float 
	// Return:
	//		Returns a Vector4 
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 Lerp(Vector4 a, Vector4 b, float t);

	//--------------------------------------------------------------------------------------
	// Distance: Returns the distance between a and b.
	//
	// Param:
	//		a: Vector4
	//		b: Vector4
	// Return:
	//		Returns a float which is the distance between a and b.
	//--------------------------------------------------------------------------------------
	MATH_DLL float Distance(Vector4 pos1, Vector4 pos2);

	//--------------------------------------------------------------------------------------
	// Bezier: A function to calculate a bezier curves.
	//
	// Param:
	//		t: A float representing time.
	//		a: Vector4 point.
	//		b: Vector4 point.
	//		c: Vector4 point.
	// Return:
	//		Returns a Vector4 value of the Bezier curve.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 Bezier(float t, Vector4 a, Vector4 b, Vector4 c);

	//--------------------------------------------------------------------------------------
	// hermiteCurve: A function to calculate a hermite Curve.
	//
	// Param:
	//		point0: Vector4 point.
	//		tangent0: Vector4 tangent.
	//		point1: Vector4 point.
	//		tangent1: Vector4 tangent.
	//		t: A float representing time.
	// Return:
	//		Returns a Vector4 value of the hermite curve.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 hermiteCurve(Vector4 point0, Vector4 tangent0, Vector4 point1, Vector4 tangent1, float t);

	//--------------------------------------------------------------------------------------
	// Swizzle: Switch around the values of x, y, z and w to every possible combo.
	//
	// Return:
	//		Returns a Vector4 value with the applied changes.
	//--------------------------------------------------------------------------------------
	//////////////// SWIZZLE ////////////////
	// Swizzle for wwww
	MATH_DLL Vector4 wwww();

	// Swizzle for wwwx
	MATH_DLL Vector4 wwwx();

	// Swizzle for wwwy
	MATH_DLL Vector4 wwwy();

	// Swizzle for wwwz
	MATH_DLL Vector4 wwwz();

	// Swizzle for wwxw
	MATH_DLL Vector4 wwxw();

	// Swizzle for wwxx
	MATH_DLL Vector4 wwxx();

	// Swizzle for wwxy
	MATH_DLL Vector4 wwxy();

	// Swizzle for wwxz
	MATH_DLL Vector4 wwxz();

	// Swizzle for wwyw
	MATH_DLL Vector4 wwyw();

	// Swizzle for wwyx
	MATH_DLL Vector4 wwyx();

	// Swizzle for wwyy
	MATH_DLL Vector4 wwyy();

	// Swizzle for wwyz
	MATH_DLL Vector4 wwyz();

	// Swizzle for wwzw
	MATH_DLL Vector4 wwzw();

	// Swizzle for wwzx
	MATH_DLL Vector4 wwzx();

	// Swizzle for wwzy
	MATH_DLL Vector4 wwzy();

	// Swizzle for wwzz
	MATH_DLL Vector4 wwzz();

	// Swizzle for wxww
	MATH_DLL Vector4 wxww();

	// Swizzle for wxwx
	MATH_DLL Vector4 wxwx();

	// Swizzle for wxwy
	MATH_DLL Vector4 wxwy();

	// Swizzle for wxwz
	MATH_DLL Vector4 wxwz();

	// Swizzle for wxxw
	MATH_DLL Vector4 wxxw();

	// Swizzle for wxxx
	MATH_DLL Vector4 wxxx();

	// Swizzle for wxxy
	MATH_DLL Vector4 wxxy();

	// Swizzle for wxxz
	MATH_DLL Vector4 wxxz();

	// Swizzle for wxyw
	MATH_DLL Vector4 wxyw();

	// Swizzle for wxyx
	MATH_DLL Vector4 wxyx();

	// Swizzle for wxyy
	MATH_DLL Vector4 wxyy();

	// Swizzle for wxyz
	MATH_DLL Vector4 wxyz();

	// Swizzle for wxzw
	MATH_DLL Vector4 wxzw();

	// Swizzle for wxzx
	MATH_DLL Vector4 wxzx();

	// Swizzle for wxzy
	MATH_DLL Vector4 wxzy();

	// Swizzle for wxzz
	MATH_DLL Vector4 wxzz();

	// Swizzle for wyww
	MATH_DLL Vector4 wyww();

	// Swizzle for wywx
	MATH_DLL Vector4 wywx();

	// Swizzle for wywy
	MATH_DLL Vector4 wywy();

	// Swizzle for wywz
	MATH_DLL Vector4 wywz();

	// Swizzle for wyxw
	MATH_DLL Vector4 wyxw();

	// Swizzle for wyxx
	MATH_DLL Vector4 wyxx();

	// Swizzle for wyxy
	MATH_DLL Vector4 wyxy();

	// Swizzle for wyxz
	MATH_DLL Vector4 wyxz();

	// Swizzle for wyyw
	MATH_DLL Vector4 wyyw();

	// Swizzle for wyyx
	MATH_DLL Vector4 wyyx();

	// Swizzle for wyyy
	MATH_DLL Vector4 wyyy();

	// Swizzle for wyyz
	MATH_DLL Vector4 wyyz();

	// Swizzle for wyzw
	MATH_DLL Vector4 wyzw();

	// Swizzle for wyzx
	MATH_DLL Vector4 wyzx();

	// Swizzle for wyzy
	MATH_DLL Vector4 wyzy();

	// Swizzle for wyzz
	MATH_DLL Vector4 wyzz();

	// Swizzle for wzww
	MATH_DLL Vector4 wzww();

	// Swizzle for wzwx
	MATH_DLL Vector4 wzwx();

	// Swizzle for wzwy
	MATH_DLL Vector4 wzwy();

	// Swizzle for wzwz
	MATH_DLL Vector4 wzwz();

	// Swizzle for wzxw
	MATH_DLL Vector4 wzxw();

	// Swizzle for wzxx
	MATH_DLL Vector4 wzxx();

	// Swizzle for wzxy
	MATH_DLL Vector4 wzxy();

	// Swizzle for wzxz
	MATH_DLL Vector4 wzxz();

	// Swizzle for wzyw
	MATH_DLL Vector4 wzyw();

	// Swizzle for wzyx
	MATH_DLL Vector4 wzyx();

	// Swizzle for wzyy
	MATH_DLL Vector4 wzyy();

	// Swizzle for wzyz
	MATH_DLL Vector4 wzyz();

	// Swizzle for wzzw
	MATH_DLL Vector4 wzzw();

	// Swizzle for wzzx
	MATH_DLL Vector4 wzzx();

	// Swizzle for wzzy
	MATH_DLL Vector4 wzzy();

	// Swizzle for wzzz
	MATH_DLL Vector4 wzzz();

	// Swizzle for xwww
	MATH_DLL Vector4 xwww();

	// Swizzle for xwwx
	MATH_DLL Vector4 xwwx();

	// Swizzle for xwwy
	MATH_DLL Vector4 xwwy();

	// Swizzle for xwwz
	MATH_DLL Vector4 xwwz();

	// Swizzle for xwxw
	MATH_DLL Vector4 xwxw();

	// Swizzle for xwxx
	MATH_DLL Vector4 xwxx();

	// Swizzle for xwxy
	MATH_DLL Vector4 xwxy();

	// Swizzle for xwxz
	MATH_DLL Vector4 xwxz();

	// Swizzle for xwyw
	MATH_DLL Vector4 xwyw();

	// Swizzle for xwyx
	MATH_DLL Vector4 xwyx();

	// Swizzle for xwyy
	MATH_DLL Vector4 xwyy();

	// Swizzle for xwyz
	MATH_DLL Vector4 xwyz();

	// Swizzle for xwzw
	MATH_DLL Vector4 xwzw();

	// Swizzle for xwzx
	MATH_DLL Vector4 xwzx();

	// Swizzle for xwzy
	MATH_DLL Vector4 xwzy();

	// Swizzle for xwzz
	MATH_DLL Vector4 xwzz();

	// Swizzle for xxww
	MATH_DLL Vector4 xxww();

	// Swizzle for xxwx
	MATH_DLL Vector4 xxwx();

	// Swizzle for xxwy
	MATH_DLL Vector4 xxwy();

	// Swizzle for xxwz
	MATH_DLL Vector4 xxwz();

	// Swizzle for xxxw
	MATH_DLL Vector4 xxxw();

	// Swizzle for xxxx
	MATH_DLL Vector4 xxxx();

	// Swizzle for xxxy
	MATH_DLL Vector4 xxxy();

	// Swizzle for xxxz
	MATH_DLL Vector4 xxxz();

	// Swizzle for xxyw
	MATH_DLL Vector4 xxyw();

	// Swizzle for xxyx
	MATH_DLL Vector4 xxyx();

	// Swizzle for xxyy
	MATH_DLL Vector4 xxyy();

	// Swizzle for xxyz
	MATH_DLL Vector4 xxyz();

	// Swizzle for xxzw
	MATH_DLL Vector4 xxzw();

	// Swizzle for xxzx
	MATH_DLL Vector4 xxzx();

	// Swizzle for xxzy
	MATH_DLL Vector4 xxzy();

	// Swizzle for xxzz
	MATH_DLL Vector4 xxzz();

	// Swizzle for xyww
	MATH_DLL Vector4 xyww();

	// Swizzle for xywx
	MATH_DLL Vector4 xywx();

	// Swizzle for xywy
	MATH_DLL Vector4 xywy();

	// Swizzle for xywz
	MATH_DLL Vector4 xywz();

	// Swizzle for xyxw
	MATH_DLL Vector4 xyxw();

	// Swizzle for xyxx
	MATH_DLL Vector4 xyxx();

	// Swizzle for xyxy
	MATH_DLL Vector4 xyxy();

	// Swizzle for xyxz
	MATH_DLL Vector4 xyxz();

	// Swizzle for xyyw
	MATH_DLL Vector4 xyyw();

	// Swizzle for xyyx
	MATH_DLL Vector4 xyyx();

	// Swizzle for xyyy
	MATH_DLL Vector4 xyyy();

	// Swizzle for xyyz
	MATH_DLL Vector4 xyyz();

	// Swizzle for xyzw
	MATH_DLL Vector4 xyzw();

	// Swizzle for xyzx
	MATH_DLL Vector4 xyzx();

	// Swizzle for xyzy
	MATH_DLL Vector4 xyzy();

	// Swizzle for xyzz
	MATH_DLL Vector4 xyzz();

	// Swizzle for xzww
	MATH_DLL Vector4 xzww();

	// Swizzle for xzwx
	MATH_DLL Vector4 xzwx();

	// Swizzle for xzwy
	MATH_DLL Vector4 xzwy();

	// Swizzle for xzwz
	MATH_DLL Vector4 xzwz();

	// Swizzle for xzxw
	MATH_DLL Vector4 xzxw();

	// Swizzle for xzxx
	MATH_DLL Vector4 xzxx();

	// Swizzle for xzxy
	MATH_DLL Vector4 xzxy();

	// Swizzle for xzxz
	MATH_DLL Vector4 xzxz();

	// Swizzle for xzyw
	MATH_DLL Vector4 xzyw();

	// Swizzle for xzyx
	MATH_DLL Vector4 xzyx();

	// Swizzle for xzyy
	MATH_DLL Vector4 xzyy();

	// Swizzle for xzyz
	MATH_DLL Vector4 xzyz();

	// Swizzle for xzzw
	MATH_DLL Vector4 xzzw();

	// Swizzle for xzzx
	MATH_DLL Vector4 xzzx();

	// Swizzle for xzzy
	MATH_DLL Vector4 xzzy();

	// Swizzle for xzzz
	MATH_DLL Vector4 xzzz();

	// Swizzle for ywww
	MATH_DLL Vector4 ywww();

	// Swizzle for ywwx
	MATH_DLL Vector4 ywwx();

	// Swizzle for ywwy
	MATH_DLL Vector4 ywwy();

	// Swizzle for ywwz
	MATH_DLL Vector4 ywwz();

	// Swizzle for ywxw
	MATH_DLL Vector4 ywxw();

	// Swizzle for ywxx
	MATH_DLL Vector4 ywxx();

	// Swizzle for ywxy
	MATH_DLL Vector4 ywxy();

	// Swizzle for ywxz
	MATH_DLL Vector4 ywxz();

	// Swizzle for ywyw
	MATH_DLL Vector4 ywyw();

	// Swizzle for ywyx
	MATH_DLL Vector4 ywyx();

	// Swizzle for ywyy
	MATH_DLL Vector4 ywyy();

	// Swizzle for ywyz
	MATH_DLL Vector4 ywyz();

	// Swizzle for ywzw
	MATH_DLL Vector4 ywzw();

	// Swizzle for ywzx
	MATH_DLL Vector4 ywzx();

	// Swizzle for ywzy
	MATH_DLL Vector4 ywzy();

	// Swizzle for ywzz
	MATH_DLL Vector4 ywzz();

	// Swizzle for yxww
	MATH_DLL Vector4 yxww();

	// Swizzle for yxwx
	MATH_DLL Vector4 yxwx();

	// Swizzle for yxwy
	MATH_DLL Vector4 yxwy();

	// Swizzle for yxwz
	MATH_DLL Vector4 yxwz();

	// Swizzle for yxxw
	MATH_DLL Vector4 yxxw();

	// Swizzle for yxxx
	MATH_DLL Vector4 yxxx();

	// Swizzle for yxxy
	MATH_DLL Vector4 yxxy();

	// Swizzle for yxxz
	MATH_DLL Vector4 yxxz();

	// Swizzle for yxyw
	MATH_DLL Vector4 yxyw();

	// Swizzle for yxyx
	MATH_DLL Vector4 yxyx();

	// Swizzle for yxyy
	MATH_DLL Vector4 yxyy();

	// Swizzle for yxyz
	MATH_DLL Vector4 yxyz();

	// Swizzle for yxzw
	MATH_DLL Vector4 yxzw();

	// Swizzle for yxzx
	MATH_DLL Vector4 yxzx();

	// Swizzle for yxzy
	MATH_DLL Vector4 yxzy();

	// Swizzle for yxzz
	MATH_DLL Vector4 yxzz();

	// Swizzle for yyww
	MATH_DLL Vector4 yyww();

	// Swizzle for yywx
	MATH_DLL Vector4 yywx();

	// Swizzle for yywy
	MATH_DLL Vector4 yywy();

	// Swizzle for yywz
	MATH_DLL Vector4 yywz();

	// Swizzle for yyxw
	MATH_DLL Vector4 yyxw();

	// Swizzle for yyxx
	MATH_DLL Vector4 yyxx();

	// Swizzle for yyxy
	MATH_DLL Vector4 yyxy();

	// Swizzle for yyxz
	MATH_DLL Vector4 yyxz();

	// Swizzle for yyyw
	MATH_DLL Vector4 yyyw();

	// Swizzle for yyyx
	MATH_DLL Vector4 yyyx();

	// Swizzle for yyyy
	MATH_DLL Vector4 yyyy();

	// Swizzle for yyyz
	MATH_DLL Vector4 yyyz();

	// Swizzle for yyzw
	MATH_DLL Vector4 yyzw();

	// Swizzle for yyzx
	MATH_DLL Vector4 yyzx();

	// Swizzle for yyzy
	MATH_DLL Vector4 yyzy();

	// Swizzle for yyzz
	MATH_DLL Vector4 yyzz();

	// Swizzle for yzww
	MATH_DLL Vector4 yzww();

	// Swizzle for yzwx
	MATH_DLL Vector4 yzwx();

	// Swizzle for yzwy
	MATH_DLL Vector4 yzwy();

	// Swizzle for yzwz
	MATH_DLL Vector4 yzwz();

	// Swizzle for yzxw
	MATH_DLL Vector4 yzxw();

	// Swizzle for yzxx
	MATH_DLL Vector4 yzxx();

	// Swizzle for yzxy
	MATH_DLL Vector4 yzxy();

	// Swizzle for yzxz
	MATH_DLL Vector4 yzxz();

	// Swizzle for yzyw
	MATH_DLL Vector4 yzyw();

	// Swizzle for yzyx
	MATH_DLL Vector4 yzyx();

	// Swizzle for yzyy
	MATH_DLL Vector4 yzyy();

	// Swizzle for yzyz
	MATH_DLL Vector4 yzyz();

	// Swizzle for yzzw
	MATH_DLL Vector4 yzzw();

	// Swizzle for yzzx
	MATH_DLL Vector4 yzzx();

	// Swizzle for yzzy
	MATH_DLL Vector4 yzzy();

	// Swizzle for yzzz
	MATH_DLL Vector4 yzzz();

	// Swizzle for zwww
	MATH_DLL Vector4 zwww();

	// Swizzle for zwwx
	MATH_DLL Vector4 zwwx();

	// Swizzle for zwwy
	MATH_DLL Vector4 zwwy();

	// Swizzle for zwwz
	MATH_DLL Vector4 zwwz();

	// Swizzle for zwxw
	MATH_DLL Vector4 zwxw();

	// Swizzle for zwxx
	MATH_DLL Vector4 zwxx();

	// Swizzle for zwxy
	MATH_DLL Vector4 zwxy();

	// Swizzle for zwxz
	MATH_DLL Vector4 zwxz();

	// Swizzle for zwyw
	MATH_DLL Vector4 zwyw();

	// Swizzle for zwyx
	MATH_DLL Vector4 zwyx();

	// Swizzle for zwyy
	MATH_DLL Vector4 zwyy();

	// Swizzle for zwyz
	MATH_DLL Vector4 zwyz();

	// Swizzle for zwzw
	MATH_DLL Vector4 zwzw();

	// Swizzle for zwzx
	MATH_DLL Vector4 zwzx();

	// Swizzle for zwzy
	MATH_DLL Vector4 zwzy();

	// Swizzle for zwzz
	MATH_DLL Vector4 zwzz();

	// Swizzle for zxww
	MATH_DLL Vector4 zxww();

	// Swizzle for zxwx
	MATH_DLL Vector4 zxwx();

	// Swizzle for zxwy
	MATH_DLL Vector4 zxwy();

	// Swizzle for zxwz
	MATH_DLL Vector4 zxwz();

	// Swizzle for zxxw
	MATH_DLL Vector4 zxxw();

	// Swizzle for zxxx
	MATH_DLL Vector4 zxxx();

	// Swizzle for zxxy
	MATH_DLL Vector4 zxxy();

	// Swizzle for zxxz
	MATH_DLL Vector4 zxxz();

	// Swizzle for zxyw
	MATH_DLL Vector4 zxyw();

	// Swizzle for zxyx
	MATH_DLL Vector4 zxyx();

	// Swizzle for zxyy
	MATH_DLL Vector4 zxyy();

	// Swizzle for zxyz
	MATH_DLL Vector4 zxyz();

	// Swizzle for zxzw
	MATH_DLL Vector4 zxzw();

	// Swizzle for zxzx
	MATH_DLL Vector4 zxzx();

	// Swizzle for zxzy
	MATH_DLL Vector4 zxzy();

	// Swizzle for zxzz
	MATH_DLL Vector4 zxzz();

	// Swizzle for zyww
	MATH_DLL Vector4 zyww();

	// Swizzle for zywx
	MATH_DLL Vector4 zywx();

	// Swizzle for zywy
	MATH_DLL Vector4 zywy();

	// Swizzle for zywz
	MATH_DLL Vector4 zywz();

	// Swizzle for zyxw
	MATH_DLL Vector4 zyxw();

	// Swizzle for zyxx
	MATH_DLL Vector4 zyxx();

	// Swizzle for zyxy
	MATH_DLL Vector4 zyxy();

	// Swizzle for zyxz
	MATH_DLL Vector4 zyxz();

	// Swizzle for zyyw
	MATH_DLL Vector4 zyyw();

	// Swizzle for zyyx
	MATH_DLL Vector4 zyyx();

	// Swizzle for zyyy
	MATH_DLL Vector4 zyyy();

	// Swizzle for zyyz
	MATH_DLL Vector4 zyyz();

	// Swizzle for zyzw
	MATH_DLL Vector4 zyzw();

	// Swizzle for zyzx
	MATH_DLL Vector4 zyzx();

	// Swizzle for zyzy
	MATH_DLL Vector4 zyzy();

	// Swizzle for zyzz
	MATH_DLL Vector4 zyzz();

	// Swizzle for zzww
	MATH_DLL Vector4 zzww();

	// Swizzle for zzwx
	MATH_DLL Vector4 zzwx();

	// Swizzle for zzwy
	MATH_DLL Vector4 zzwy();

	// Swizzle for zzwz
	MATH_DLL Vector4 zzwz();

	// Swizzle for zzxw
	MATH_DLL Vector4 zzxw();

	// Swizzle for zzxx
	MATH_DLL Vector4 zzxx();

	// Swizzle for zzxy
	MATH_DLL Vector4 zzxy();

	// Swizzle for zzxz
	MATH_DLL Vector4 zzxz();

	// Swizzle for zzyw
	MATH_DLL Vector4 zzyw();

	// Swizzle for zzyx
	MATH_DLL Vector4 zzyx();

	// Swizzle for zzyy
	MATH_DLL Vector4 zzyy();

	// Swizzle for zzyz
	MATH_DLL Vector4 zzyz();

	// Swizzle for zzzw
	MATH_DLL Vector4 zzzw();

	// Swizzle for zzzx
	MATH_DLL Vector4 zzzx();

	// Swizzle for zzzy
	MATH_DLL Vector4 zzzy();

	// Swizzle for zzzz
	MATH_DLL Vector4 zzzz();
	//////////////// SWIZZLE ////////////////

	//--------------------------------------------------------------------------------------
	// Union creating the x, y, z and w for the vector class. Using a union so we can have both floats and an array of floats
	//--------------------------------------------------------------------------------------
	union
	{
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};

		float vec[4];
	};
};

//--------------------------------------------------------------------------------------
// Multiply float by vector: Overloads the "*" operator so that floats can be Multiplied by Vector4s.
//
// Param:
//		lhs: The float you would like to multiply by the Vector4.
//		rhs: The Vector4 you would like to be multiplied by the float.
// Return:
//		Returns a Vector4 value equel to the values you Multiplied by.
//
// (out side of class so we can order)
//--------------------------------------------------------------------------------------
MATH_DLL Vector4 operator*(float lhs, const Vector4& rhs);