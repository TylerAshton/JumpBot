#pragma once

#include <iostream>
#include <string>

#define SDL_MAIN_HANDLED
#include <SDL.h>

const int screenWidth = 800;
const int screenHeight = 600;


class GameLoop
{
public: int init();

	  void update();
	  void render();

	  void clean();
private:

};

