#pragma once
#include "Entity.h"
#include "Renderer2D.h"
#include "Matrix3.h"
#include "Texture.h"
#include "Input.h"
using namespace aie;

class Player : public Entity
{
public:
	Player();
	~Player();

	void Update(float deltaTime);
	void Draw(aie::Renderer2D* renderer2D);

	Texture* playerTexture;
	Renderer2D* renderer2D;

	float rotSpeed;
	float speed;
};