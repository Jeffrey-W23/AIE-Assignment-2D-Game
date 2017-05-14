//#include, using etc
#include "Application2D.h"
#include "Vector2.h"
#include "CollisionManager.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Application2D::Application2D() 
{
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Application2D::~Application2D() 
{
}

//--------------------------------------------------------------------------------------
// startup: Initialize the game.
//
// Returns:
//		bool: Returns a true or false for if the startup is sucessful.
//--------------------------------------------------------------------------------------
bool Application2D::startup() 
{
	// Create instance for the collision manger
	CollisionManager::Create();

	// Create a new instance of the Renderer2D
	m_2dRenderer = new Renderer2D();

	// Add font and audio file.
	m_font = new Font("./font/consolas.ttf", 32);
	m_audio = new Audio("./audio/powerup.wav");
	
	// Create instance of Player and the map
	player = new Player("LargeShip");
	map = new Map();

	// initialize camera.
	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

//--------------------------------------------------------------------------------------
// shutdown: Called on application shutdown and does all the cleaning up (eg. Deleteing pointers.)
//--------------------------------------------------------------------------------------
void Application2D::shutdown() 
{
	// Call the collision destroy fucntion to delete all bounding boxes.
	CollisionManager::Destory();

	// delete everything
	delete player;
	delete map;
	delete m_audio;
	delete m_font;
	delete m_2dRenderer;
}

//--------------------------------------------------------------------------------------
// Update: A virtual function to update objects.
//
// Param:
//		deltaTime: Pass in deltaTime. A number that updates per second.
//--------------------------------------------------------------------------------------
void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;
	player->Update(deltaTime);
}

//--------------------------------------------------------------------------------------
// Draw: A virtual function to render (or "draw") objects to the screen.
//--------------------------------------------------------------------------------------
void Application2D::draw() 
{
	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();
	
	// Draw/Render the player
	player->Draw(m_2dRenderer);

	// Draw/Render the map
	map->Draw(m_2dRenderer);

	// done drawing sprites
	m_2dRenderer->end();
}