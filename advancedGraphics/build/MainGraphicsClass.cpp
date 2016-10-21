#include "MainGraphicsClass.h"
#include <iostream>
#include <string>


MainGraphicsClass::MainGraphicsClass()
{
	_window = nullptr;
	_screenWidth = 1000;
	_screenHeight = 800;
	_gameState = GameState::PLAY;
}


MainGraphicsClass::~MainGraphicsClass()
{
}

void MainGraphicsClass ::Render()
{
	initSystem();
	MainLoop();
}

void ErrorCatching(std::string errorString)
{
	std::cout << errorString << std::endl;
	std::cout << "Error; Press Any key to quit...";
		int key;
	std::cin >> key;
	SDL_QUIT;
	exit(1);
}

void MainGraphicsClass::initSystem()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION,
			"SDL_Init Error: %s\n", SDL_GetError());
	}
	else
		SDL_Log("[SDL] initialised OK!\n");

	_window = SDL_CreateWindow("Advance Graphics", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);

	if (_window == nullptr)
	{
		ErrorCatching("SDL WINDOW COULD NOT BE CREATED");
	}

	SDL_GLContext glContex = SDL_GL_CreateContext(_window);
	if (glContex == nullptr)
	{
		ErrorCatching("SDL_GL context could not be initizised");
	}

	GLenum error = glewInit();
	if (error != GLEW_OK)
		ErrorCatching("Could not Initizise GLEW");

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); //Double buffer, two windows one which draws and one which clears, keeps it smooth.

	glClearColor(0.5f, 0.6f, 1.0f, 1.0f);

}

void MainGraphicsClass::MainLoop()
{
	while (_gameState != GameState::EXIT) ///Process imputs while enum = play
	{
		Imputs();
		Draw();
	}

}

void MainGraphicsClass::Imputs()
{
	SDL_Event evnt; // USes a pointer

	while (SDL_PollEvent(&evnt))
	{
		switch (evnt.type) 
		{
		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			std::cout << evnt.motion.x << " _ " << evnt.motion.y << std::endl;//Check poision of mouse motion
		}
	}
}

void MainGraphicsClass::Draw()
{
	glClearDepth(1.0); //What dept to clear too
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Clear the buffer when starts, | = bit wise or

	glEnableClientState(GL_COLOR_ARRAY);
	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0, 0);
	glVertex2f(0, 400);
	glVertex2f(400, 400);
	

	glEnd();

	SDL_GL_SwapWindow(_window); //Switch buffer so that one draws and one clears 
}
