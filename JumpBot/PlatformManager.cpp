#include "PlatformManager.h"

PlatformManager::PlatformManager(SDL_Renderer* sdlRenderer, Player* Platplayer)
{
	renderer = sdlRenderer;
	player = Platplayer;
}

int PlatformManager::init()
{
	for (int i = 0; i < 3; i++) {
		addPlat(std::unique_ptr <Platform>(new Platform(renderer, player, SDL_FPoint{ 0, (float)100 * (i+1) })));
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
