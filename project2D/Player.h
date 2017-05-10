#pragma once
#include "Entity.h"
#include "Renderer2D.h"
#include "Matrix3.h"
#include "Texture.h"
#include "Input.h"
#include "CollisionManager.h"
#include "turret.h"
#include "rect.h"
#include <iostream>
using namespace std;
using namespace aie;

class Player : public Entity
{
public:
	Player(char* textureUrl);
	~Player();

	void Update(float deltaTime);
	void Draw(Renderer2D* renderer2D);

	float rotSpeed;
	turret* Turret;

private:
	rect boundingBox;
};