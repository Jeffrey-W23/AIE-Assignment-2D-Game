#pragma once
#include "Vector4.h"

class Matrix4
{
public:
	Matrix4();
	Matrix4(float Xx, float Yx, float Zx, float Tx, float Xy, float Yy, float Zy, float Ty, float Xz, float Yz, float Zz, float Tz, float Xw, float Yw, float Zw, float Tw);
	~Matrix4();

	Vector4 operator*(const Vector4& rhs);
	Matrix4 operator*(const Matrix4& rhs);

	float m[16];
};

