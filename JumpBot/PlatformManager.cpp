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

	int previousY;
	int previousX;

	int newY;
	int newX;

	int playerDim = 100;

	for (int i = 0; i < 10; i++)
	{
		if (i == 0) {
			addPlat(std::unique_ptr <Platform>(new Platform(renderer, player, SDL_FPoint{ (float)(rand() % (screenResolution::get_screenWidth() + 1 - playerDim)), (float)200 })));
			platforms[i]->init();
		}
		else
		{
			previousY = platforms.at(i - 1).get()->collider.y;
			previousX = platforms.at(i - 1).get()->collider.x;
			
			newX = ( -250 + rand() % 501) + previousX;

			while ((newX < 0) || (newX > screenResolution::get_screenWidth() - playerDim))
			{
				newX = (-250 + rand() % 501) + previousX;
			}

			std::cout << newX << std::endl;

			addPlat(std::unique_ptr <Platform>(new Platform(renderer, player, SDL_FPoint{ (float)newX, (float)((previousY + 75 + rand() % (201)))})));

			platforms[i]->init();
		}
		
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
