#pragma once

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <iostream>
#include <string>

const int screenWidth = 800;
const int screenHeight = 600;

class GameLoop
{
public:
	int init();

	void update();
	void render();

	bool keepAlive();

	void clean();
private:

};

