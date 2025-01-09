#pragma once

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <iostream>
#include <string>
#include "Player.h"

const int screenWidth = 800;
const int screenHeight = 600;

class GameLoop
{
public:
	int init();

	void update();
	void render();

	void handleInput(SDL_Scancode& keyScanCode);

	bool keepAlive();

	void clean();
private:
	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;
	SDL_Renderer* renderer = nullptr;

	Player* player = nullptr;
};

