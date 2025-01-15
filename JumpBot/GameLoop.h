#pragma once

#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <iostream>
#include <string>
#include "Player.h"
#include "TiledMap.h"
#include "screenResolution.h"
#include "Platform.h"
#include "PlatformManager.h"
#include "FontRenderer.h"

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
	std::unique_ptr<FontRenderer> fontRenderer;
	std::unique_ptr<TiledMap> tiledMap;

	Player* player = nullptr;

	//std::unique_ptr <Platform> platform = nullptr;
	//std::unique_ptr <Platform> platform1 = nullptr;
	//std::unique_ptr <Platform> platform2 = nullptr;

	PlatformManager* platMan = nullptr;
};

