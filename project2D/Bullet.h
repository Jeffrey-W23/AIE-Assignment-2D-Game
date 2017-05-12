#pragma once
#include "Entity.h"

class Bullet : public Entity
{
public:
	Bullet(char* textureUrl, Vector2 pos, float rad);
	~Bullet();

	void Update(float deltaTime);
	void Draw(Renderer2D* renderer2D);
	void SetDir(Vector2 dir);

private:
	float speed;
	float rad;
	Vector2 dir;
};

