#pragma once
#include "Wall.h"
#include "Renderer2D.h"

class Map
{
public:
	Map();
	~Map();

	void Update(float deltaTime);
	void Draw(Renderer2D* renderer2D);

	Wall* wall1;
	Wall* wall2;
	Wall* wall3;
	Wall* wall4;
	Wall* wall5;
	Wall* wall6;
};