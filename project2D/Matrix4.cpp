#include "Matrix4.h"

Matrix4::Matrix4()
{
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = 0;
	m[5] = 1;
	m[6] = 0;
	m[7] = 0;
	m[8] = 0;
	m[9] = 0;
	m[10] = 1;
	m[11] = 0;
	m[12] = 0;
	m[13] = 0;
	m[14] = 0;
	m[15] = 1;
}

Matrix4::Matrix4(float Xx, float Yx, float Zx, float Tx, float Xy, float Yy, float Zy, float Ty, float Xz, float Yz, float Zz, float Tz, float Xw, float Yw, float Zw, float Tw)
{
	m[0] = Xx;
	m[1] = Yx;
	m[2] = Zx;
	m[3] = Tx;
	m[4] = Xy;
	m[5] = Yy;
	m[6] = Zy;
	m[7] = Ty;
	m[8] = Xz;
	m[9] = Yz;
	m[10] = Zz;
	m[11] = Tz;
	m[12] = Xw;
	m[13] = Yw;
	m[14] = Zw;
	m[15] = Tw;
}

Matrix4::~Matrix4()
{

}

Vector4 Matrix4::operator*(const Vector4& rhs)
{
	Vector4 result;

	result.x = m[0] * rhs.x + m[1] * rhs.y + m[2] * rhs.z + m[3] * rhs.w;
	result.y = m[4] * rhs.x + m[5] * rhs.y + m[6] * rhs.z + m[7] * rhs.w;
	result.z = m[8] * rhs.x + m[9] * rhs.y + m[10] * rhs.z + m[11] * rhs.w;
	result.w = m[12] * rhs.x + m[13] * rhs.y + m[14] * rhs.z + m[155] * rhs.w;

	return result;
}

Matrix4 Matrix4::operator*(const Matrix4& rhs)
{
	Matrix4 result;

	return result;
}