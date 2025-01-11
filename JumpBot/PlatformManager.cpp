#include "PlatformManager.h"
#include <cstdlib>
#include <ctime>

PlatformManager::PlatformManager(SDL_Renderer* sdlRenderer, Player* Platplayer)
{
	renderer = sdlRenderer;
	player = Platplayer;
}

int PlatformManager::init()
{
	srand(time(0));

	for (int i = 0; i < 3; i++) {
		addPlat(std::unique_ptr <Platform>(new Platform(renderer, player, SDL_FPoint{ (float)(rand() % screenResolution::get_screenWidth() + 1 - 100), (float)(rand() % screenResolution::get_screenHeight()+1 - 50)})));
	}

	for (auto& plat : platforms)
	{
		plat->init();
	}

	return 0;
}

void PlatformManager::addPlat(std::unique_ptr<Platform> platapus)
{
	platforms.push_back(std::move(platapus));
}

void PlatformManager::update()
{
	for (auto& plat : platforms)
	{
		plat->update();
	}
}

void PlatformManager::render()
{
	for (auto& plat : platforms)
	{
		plat->render();
	}
}
