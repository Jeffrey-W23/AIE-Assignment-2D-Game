// #includes, using, etc
#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Player.h"
#include "Map.h"
using namespace aie;

class Application2D : public Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	Renderer2D* m_2dRenderer;
	Texture* m_shipTexture;
	Font* m_font;
	Audio* m_audio;
	
	float m_cameraX, m_cameraY;
	float m_timer;

	Player* player;
	Map* map;
};