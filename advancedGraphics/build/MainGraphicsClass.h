#pragma once

#include <SDL.h>
#include <gl\glew.h>
#include <SDL_opengl.h>
#include <gl\glu.h>

enum class GameState {PLAY, EXIT};

enum class ErrorState { ERROR, CRITICAL, FATAL };

class MainGraphicsClass
{
public:
	MainGraphicsClass();
	~MainGraphicsClass();

	void Render();
	void MainLoop();
	void Imputs();
	void Draw();

private:
	SDL_Window* _window; //Returns a pointer

	void initSystem();
	int _screenHeight;
	int _screenWidth;
	GameState _gameState;
	ErrorState _errorState;
};

