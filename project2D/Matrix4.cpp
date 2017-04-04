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
	result.w = m[12] * rhs.x + m[13] * rhs.y + m[14] * rhs.z + m[15] * rhs.w;

	return result;
}

Matrix4 Matrix4::operator*(const Matrix4& rhs)
{
	Matrix4 result;

	result.m[0] = m[0] * rhs.m[0] + m[1] * rhs.m[4] + m[2] * rhs.m[8] + m[3] * rhs.m[12];
	result.m[1] = m[0] * rhs.m[1] + m[1] * rhs.m[5] + m[2] * rhs.m[9] + m[3] * rhs.m[13];
	result.m[2] = m[0] * rhs.m[2] + m[1] * rhs.m[6] + m[2] * rhs.m[10] + m[3] * rhs.m[14];
	result.m[3] = m[0] * rhs.m[3] + m[1] * rhs.m[7] + m[2] * rhs.m[11] + m[3] * rhs.m[15];

	result.m[4] = m[4] * rhs.m[0] + m[5] * rhs.m[4] + m[6] * rhs.m[8] + m[7] * rhs.m[12];
	result.m[5] = m[4] * rhs.m[1] + m[5] * rhs.m[5] + m[6] * rhs.m[9] + m[7] * rhs.m[13];
	result.m[6] = m[4] * rhs.m[2] + m[5] * rhs.m[6] + m[6] * rhs.m[10] + m[7] * rhs.m[14];
	result.m[7] = m[4] * rhs.m[3] + m[5] * rhs.m[7] + m[6] * rhs.m[11] + m[7] * rhs.m[15];

	result.m[8] = m[8] * rhs.m[0] + m[9] * rhs.m[4] + m[10] * rhs.m[8] + m[11] * rhs.m[12];
	result.m[9] = m[8] * rhs.m[1] + m[9] * rhs.m[5] + m[10] * rhs.m[9] + m[11] * rhs.m[13];
	result.m[10] = m[8] * rhs.m[2] + m[9] * rhs.m[6] + m[10] * rhs.m[10] + m[11] * rhs.m[14];
	result.m[11] = m[8] * rhs.m[3] + m[9] * rhs.m[7] + m[10] * rhs.m[11] + m[11] * rhs.m[15];

	result.m[12] = m[12] * rhs.m[0] + m[13] * rhs.m[4] + m[14] * rhs.m[8] + m[15] * rhs.m[12];
	result.m[13] = m[12] * rhs.m[1] + m[13] * rhs.m[5] + m[14] * rhs.m[9] + m[15] * rhs.m[13];
	result.m[14] = m[12] * rhs.m[2] + m[13] * rhs.m[6] + m[14] * rhs.m[10] + m[15] * rhs.m[14];
	result.m[15] = m[12] * rhs.m[3] + m[13] * rhs.m[7] + m[14] * rhs.m[11] + m[15] * rhs.m[15];

	return result;
}

// Sub-script operator returning a reference 
Vector4& Matrix4::operator[](const int rhs)
{
	return *(Vector4*)(m + 4 * rhs);
}

// Cast operator to float pointer
Matrix4::operator float*()
{
	return &m[0];
}

// Set Rotation X
void Matrix4::setRotateX(const float a)
{
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = 0;
	m[5] = cos(a);
	m[6] = -sin(a);
	m[7] = 0;
	m[8] = 0;
	m[9] = sin(a);
	m[10] = cos(a);
	m[11] = 0;
	m[12] = 0;
	m[13] = 0;
	m[14] = 0;
	m[15] = 1;
}

// Set Rotation Y
void Matrix4::setRotateY(const float a)
{
	m[0] = cos(a);
	m[1] = 0;
	m[2] = -sin(a);
	m[3] = 0;
	m[4] = 0;
	m[5] = 1;
	m[6] = 0;
	m[7] = 0;
	m[8] = sin(a);
	m[9] = 0;
	m[10] = cos(a);
	m[11] = 0;
	m[12] = 0;
	m[13] = 0;
	m[14] = 0;
	m[15] = 1;
}

// Set Rotation Z
void Matrix4::setRotateZ(const float a)
{
	m[0] = cos(a);
	m[1] = -sin(a);
	m[2] = 0;
	m[3] = 0;
	m[4] = sin(a);
	m[5] = cos(a);
	m[6] = 0;
	m[7] = 0;
	m[8] = 0;
	m[9] = 0;
	m[10] = 0;
	m[11] = 1;
	m[12] = 0;
	m[13] = 0;
	m[14] = 0;
	m[15] = 1;
}

// Set Scale
void Matrix4::setScale(const float x, const float y, const float z, const float w)
{
	m[0] = x;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = 0;
	m[5] = y;
	m[6] = 0;
	m[7] = 0;
	m[8] = 0;
	m[9] = 0;
	m[10] = z;
	m[11] = 0;
	m[12] = 0;
	m[13] = 0;
	m[14] = 0;
	m[15] = 1;
}

// Set postion taking in a vector
void Matrix4::setPostionv(const Vector3& rhs)
{
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = rhs.x;
	m[4] = 0;
	m[5] = 1;
	m[6] = 0;
	m[7] = rhs.y;
	m[8] = 0;
	m[9] = 0;
	m[10] = 1;
	m[11] = rhs.z;
	m[12] = 0;
	m[13] = 0;
	m[14] = 0;
	m[15] = 1;
}

// Set postion taking in a float
void Matrix4::setPostionf(const float x, const float y, const float z)
{
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = x;
	m[4] = 0;
	m[5] = 1;
	m[6] = 0;
	m[7] = y;
	m[8] = 0;
	m[9] = 0;
	m[10] = 1;
	m[11] = z;
	m[12] = 0;
	m[13] = 0;
	m[14] = 0;
	m[15] = 1;
}