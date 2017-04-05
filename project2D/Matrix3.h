#pragma once
#include "Vector3.h"
#include "Vector2.h"

class Matrix3
{
public:
	Matrix3();
	Matrix3(float Xx, float Xy, float Xz, float Yx, float Yy, float Yz, float Zx, float Zy, float Zz);
	~Matrix3();

	Vector3 operator*(const Vector3& rhs);
	Matrix3 operator*(const Matrix3& rhs);

	// Sub-script operator returning a reference 
	Vector3& operator[](const int rhs);

	// Cast operator to float pointer
	operator float*();

	// Set Rotation X
	void setRotateX(const float a);

	// Set Rotation Y
	void setRotateY(const float a);

	// Set Rotation Z
	void setRotateZ(const float a);

	// Set Scale
	void setScale(const float x, const float y, const float z);

	// Set postion taking in a vector
	void setPostionv(const Vector2& rhs);

	// Set postion taking in a float
	void setPostionf(const float x, const float y);

	float m[9];
};

