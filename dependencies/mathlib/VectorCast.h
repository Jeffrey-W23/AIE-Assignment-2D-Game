// #include, using, etc
#pragma once
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"

//--------------------------------------------------------------------------------------
// Set up CastTo template.
//--------------------------------------------------------------------------------------
template <class D, class S>
static D CastTo(S source) {};

//--------------------------------------------------------------------------------------
// Cast a Vector2 to Vector3
//
// Param:
//		source: the vector you want to cast from.
// Return:
//		Returns a Vector3 from a Vector2.
//--------------------------------------------------------------------------------------
template <>
static Vector3 CastTo(Vector2 source) 
{
	return Vector3(source.x, source.y, 0);
};

//--------------------------------------------------------------------------------------
// Cast a Vector3 to Vector2
//
// Param:
//		source: the vector you want to cast from.
// Return:
//		Returns a Vector2 from a Vector3.
//--------------------------------------------------------------------------------------
template <>
static Vector2 CastTo(Vector3 source)
{
	return Vector2(source.x, source.y);
};

//--------------------------------------------------------------------------------------
// Cast a Vector4 to Vector2
//
// Param:
//		source: the vector you want to cast from.
// Return:
//		Returns a Vector2 from a Vector4.
//--------------------------------------------------------------------------------------
template <>
static Vector2 CastTo(Vector4 source)
{
	return Vector2(source.x, source.y);
};

//--------------------------------------------------------------------------------------
// Cast a Vector2 to Vector4
//
// Param:
//		source: the vector you want to cast from.
// Return:
//		Returns a Vector4 from a Vector2.
//--------------------------------------------------------------------------------------
template <>
static Vector4 CastTo(Vector2 source)
{
	return Vector4(source.x, source.y, 0 , 0);
};

//--------------------------------------------------------------------------------------
// Cast a Vector4 to Vector3
//
// Param:
//		source: the vector you want to cast from.
// Return:
//		Returns a Vector3 from a Vector4.
//--------------------------------------------------------------------------------------
template <>
static Vector3 CastTo(Vector4 source)
{
	return Vector3(source.x, source.y, source.z);
};

//--------------------------------------------------------------------------------------
// Cast a Vector3 to Vector4
//
// Param:
//		source: the vector you want to cast from.
// Return:
//		Returns a Vector4 from a Vector3.
//--------------------------------------------------------------------------------------
template <>
static Vector4 CastTo(Vector3 source)
{
	return Vector4(source.x, source.y, source.z, 0);
};