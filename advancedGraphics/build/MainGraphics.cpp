#include "MainGraphics.h"



MainGraphics::MainGraphics()
{
	_window = nullptr;
	_screenWidth = 1000;
	_screenHeight = 800;
}


MainGraphics::~MainGraphics()
{
}


void MainGraphics::Render() 
{
	initSystem();
}

void MainGraphics::initSystem() 
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 
	{
		SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION,
			"SDL_Init Error: %s\n", SDL_GetError());
	}
	else
	SDL_Log("[SDL] initialised OK!\n");

	_window = SDL_CreateWindow("Advance Graphics", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
}