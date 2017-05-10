#include "Map.h"

Map::Map()
{
	wall1 = new Wall(nullptr, Vector2(0, -100), Vector2(50, 50));
	wall2 = new Wall(nullptr, Vector2(0, 400), Vector2(50, 50));
	wall3 = new Wall(nullptr, Vector2(-487, 150), Vector2(50, 50));
	wall4 = new Wall(nullptr, Vector2(488, 150), Vector2(50, 50));
}

Map::~Map()
{
}

void Map::Draw(Renderer2D* renderer2D)
{
	wall1->Draw(renderer2D);
	wall2->Draw(renderer2D);
	wall3->Draw(renderer2D);
	wall4->Draw(renderer2D);
}

void Map::Update(float deltaTime)
{
}