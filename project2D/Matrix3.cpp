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

	result.m[0] = m[0] * rhs.m[0] + m[1] * rhs.m[3] + m[2] * rhs.m[6];
	result.m[1] = m[0] * rhs.m[1] + m[1] * rhs.m[4] + m[2] * rhs.m[7];
	result.m[2] = m[0] * rhs.m[2] + m[1] * rhs.m[5] + m[2] * rhs.m[8];

	result.m[3] = m[3] * rhs.m[0] + m[4] * rhs.m[3] + m[5] * rhs.m[6];
	result.m[4] = m[3] * rhs.m[1] + m[4] * rhs.m[4] + m[5] * rhs.m[7];
	result.m[5] = m[3] * rhs.m[2] + m[4] * rhs.m[5] + m[5] * rhs.m[8];

	result.m[6] = m[6] * rhs.m[0] + m[7] * rhs.m[3] + m[8] * rhs.m[6];
	result.m[7] = m[6] * rhs.m[1] + m[7] * rhs.m[4] + m[8] * rhs.m[7];
	result.m[8] = m[6] * rhs.m[2] + m[7] * rhs.m[5] + m[8] * rhs.m[8];

	return result;
}

// Sub-script operator returning a reference 
Vector3& Matrix3::operator[](const int rhs)
{
	return *(Vector3*)(m + 3 * rhs);
}

// Cast operator to float pointer
Matrix3::operator float*()
{
	return &m[0];
}

// Set Rotation X
void Matrix3::setRotateX(const float a)
{
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = cos(a);
	m[5] = -sin(a);
	m[6] = 0;
	m[7] = sin(a);
	m[8] = cos(a);
}

// Set Rotation Y
void Matrix3::setRotateY(const float a)
{
	m[0] = cos(a);
	m[1] = 0;
	m[2] = -sin(a);
	m[3] = 0;
	m[4] = 1;
	m[5] = 0;
	m[6] = sin(a);
	m[7] = 0;
	m[8] = cos(a);
}

// Set Rotation Z
void Matrix3::setRotateZ(const float a)
{
	m[0] = cos(a);
	m[1] = -sin(a);
	m[2] = 0;
	m[3] = sin(a);
	m[4] = cos(a);
	m[5] = 0;
	m[6] = 0;
	m[7] = 0;
	m[8] = 1;
}

// Set Scale
void Matrix3::setScale(const float x, const float y, const float z)
{
	m[0] = x;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = y;
	m[5] = 0;
	m[6] = 0;
	m[7] = 0;
	m[8] = z;
}

// Set postion taking in a vector
void Matrix3::setPostionv(const Vector2& rhs)
{
	m[0] = 1;
	m[1] = 0;
	m[2] = rhs.x;
	m[3] = 0;
	m[4] = 1;
	m[5] = rhs.y;
	m[6] = 0;
	m[7] = 0;
	m[8] = 1;
}

// Set postion taking in a float
void Matrix3::setPostionf(const float x, const float y)
{
	m[0] = 1;
	m[1] = 0;
	m[2] = x;
	m[3] = 0;
	m[4] = 1;
	m[5] = y;
	m[6] = 0;
	m[7] = 0;
	m[8] = 1;
}