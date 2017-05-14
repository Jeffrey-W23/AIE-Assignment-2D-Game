// #include, using, etc
#pragma once
#include "Vector2.h"

// Struct Collider holding corner and/or radius for AABB objects.
struct Collider
{
	// Top Left
	Vector2 m_TL;

	// Bottom Right
	Vector2 m_BR;

	// Radius
	float m_rad;
};