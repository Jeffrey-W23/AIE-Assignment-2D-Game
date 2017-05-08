#pragma once
#include "Entity.h"
#include "CollisionManager.h"

class Wall : public Entity
{
public:
	Wall(char* textureUrl, Vector2 pos, Vector2 size);
	~Wall();

	void Update(float deltaTime);
	void Draw(Renderer2D* renderer2D);

	Vector2 pos;
	Vector2 size;
};