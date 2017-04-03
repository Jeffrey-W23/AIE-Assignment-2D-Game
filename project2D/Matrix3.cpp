#include "Matrix3.h"

Matrix3::Matrix3::Matrix3()
{
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = 1;
	m[5] = 0;
	m[6] = 0;
	m[7] = 0;
	m[8] = 1;
}

Matrix3::Matrix3(float Xx, float Yx, float Zx, float Xy, float Yy, float Zy, float Xz, float Yz, float Zz)
{
	m[0] = Xx;
	m[1] = Yx;
	m[2] = Zx;
	m[3] = Xy;
	m[4] = Yy;
	m[5] = Zy;
	m[6] = Xz;
	m[7] = Yz;
	m[8] = Zz;
}

Matrix3::~Matrix3()
{
}

Vector3 Matrix3::operator*(const Vector3& rhs)
{
	Vector3 result;

	result.x = m[0] * rhs.x + m[1] * rhs.y + m[2] * rhs.z;
	result.y = m[3] * rhs.x + m[4] * rhs.y + m[5] * rhs.z;
	result.z = m[6] * rhs.x + m[7] * rhs.y + m[8] * rhs.z;

	return result;
}

Matrix3 Matrix3::operator*(const Matrix3& rhs)
{
	Matrix3 result;

	return result;
}