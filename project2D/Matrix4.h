#pragma once
#include "Vector4.h"
#include "Vector3.h"

class Matrix4
{
public:
	Matrix4();
	Matrix4(float Xx, float Yx, float Zx, float Tx, float Xy, float Yy, float Zy, float Ty, float Xz, float Yz, float Zz, float Tz, float Xw, float Yw, float Zw, float Tw);
	~Matrix4();

	Vector4 operator*(const Vector4& rhs);
	Matrix4 operator*(const Matrix4& rhs);

	// Sub-script operator returning a reference 
	Vector4& operator[](const int rhs);

	// Cast operator to float pointer
	operator float*();

	// Set Rotation X
	void setRotateX(const float a);

	// Set Rotation Y
	void setRotateY(const float a);

	// Set Rotation Z
	void setRotateZ(const float a);

	// Set Scale
	void setScale(const float x, const float y, const float z, const float w);

	// Set postion taking in a vector
	void setPostionv(const Vector3& rhs);

	// Set postion taking in a float
	void setPostionf(const float x, const float y, const float z);

	float m[16];
};

