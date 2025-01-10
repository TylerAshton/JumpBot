#pragma once

#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <iostream>
#include <string>
#include "Player.h"
#include "TiledMap.h"

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
	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;
	SDL_Renderer* renderer = nullptr;
	//Font goes here
	std::unique_ptr<TiledMap> tiledMap;

	Player* player = nullptr;
};

