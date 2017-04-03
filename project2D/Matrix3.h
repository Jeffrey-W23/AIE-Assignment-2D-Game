#pragma once
#include "Vector3.h"

class Matrix3
{
public:
	Matrix3();
	Matrix3(float Xx, float Yx, float Zx, float Xy, float Yy, float Zy, float Xz, float Yz, float Zz);
	~Matrix3();

	Vector3 operator*(const Vector3& rhs);
	Matrix3 operator*(const Matrix3& rhs);

	float m[9];
};

