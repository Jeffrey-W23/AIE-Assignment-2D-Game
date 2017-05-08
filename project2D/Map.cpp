#include "Map.h"

Map::Map()
{
	wall1 = new Wall(nullptr, Vector2(0, 0), Vector2(50, 50));
	wall2 = new Wall(nullptr, Vector2(10, 10), Vector2(50, 50));
	wall3 = new Wall(nullptr, Vector2(20, 20), Vector2(50, 50));
	wall4 = new Wall(nullptr, Vector2(30, 30), Vector2(50, 50));
	wall5 = new Wall(nullptr, Vector2(40, 40), Vector2(50, 50));
	wall6 = new Wall(nullptr, Vector2(50, 50), Vector2(50, 50));
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
	wall5->Draw(renderer2D);
	wall6->Draw(renderer2D);
}

void Map::Update(float deltaTime)
{
}