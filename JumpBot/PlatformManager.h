#pragma once

#include <vector>
#include <deque>
#include "Platform.h"

class PlatformManager
{
public:
	PlatformManager(SDL_Renderer* sdlRenderer, Player* Platplayer);
	//std::vector<std::unique_ptr<Platform>> platforms = {};
	std::deque<std::unique_ptr<Platform>> platforms = {};

	int init();
	void update();
	void render();
	void addPlat(std::unique_ptr<Platform> plats);

	void generatePlatform();

	void scroll();

private:
	int previousY;
	int previousX;
	int newY;
	int newX;

	int playerDim = 100;

	Player* player;
	SDL_Renderer* renderer = nullptr;
};