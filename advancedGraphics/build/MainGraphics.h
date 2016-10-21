#pragma once

#include <SDL.h>

class MainGraphics
{
public:
		MainGraphics();//Constructor

		~MainGraphics();//Destructor

		void MainGraphics::Render();

	void MainGraphics::initSystem();
	int _screenHeight;
	int _screenWidth;

private:
	SDL_Window* _window; //Returns a pointer
};

