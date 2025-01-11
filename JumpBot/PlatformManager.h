#pragma once

#include <vector>
#include "Platform.h"

class PlatformManager
{
public:
	PlatformManager(SDL_Renderer* sdlRenderer, Player* Platplayer);
	std::vector<std::unique_ptr<Platform>> platforms = {};

	int init();
	void update();
	void render();
	void addPlat(std::unique_ptr<Platform> plats);

private:
	Player* player;
	SDL_Renderer* renderer = nullptr;
};

