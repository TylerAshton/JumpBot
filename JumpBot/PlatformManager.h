#pragma once

#include <vector>
#include <deque>
#include "Platform.h"
#include "Utility.h"

class PlatformManager
{
public:
	PlatformManager(SDL_Renderer* sdlRenderer, Player* Platplayer, float Score);
	//std::vector<std::unique_ptr<Platform>> platforms = {};
	std::deque<std::unique_ptr<Platform>> platforms = {}; // Using this over vectors that way I can access either end to generate and delete.

	int init();
	void update();
	void render();
	void addPlat(std::unique_ptr<Platform> plats);

	void generatePlatform();

	void scroll();

private:
	float score;
	int previousY;
	int previousX;
	int newY;
	int newX;

	int playerDim = 100;

	Player* player;
	SDL_Renderer* renderer = nullptr;
};