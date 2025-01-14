#include "PlatformManager.h"
#include <cstdlib>
#include <ctime>

PlatformManager::PlatformManager(SDL_Renderer* sdlRenderer, Player* Platplayer, float Score)
{
	renderer = sdlRenderer;
	player = Platplayer;
	score = Score;
}

int PlatformManager::init()
{
	srand(time(0));

	for (int i = 0; i < 10; i++)
	{
		if (i == 0)
		{
			addPlat(std::unique_ptr <Platform>(new Platform(renderer, player, SDL_FPoint{ (float)(rand() % (screenResolution::get_screenWidth() + 1 - playerDim)), (float)200 })));
			platforms[i]->init();
		}
		else
		{
			/*previousY = platforms.at(i - 1).get()->collider.y;
			previousX = platforms.at(i - 1).get()->collider.x;
			
			newX = ( -250 + rand() % 501) + previousX;

			while ((newX < 0) || (newX > screenResolution::get_screenWidth() - playerDim))
			{
				newX = (-250 + rand() % 501) + previousX;
			}

			std::cout << newX << std::endl;

			addPlat(std::unique_ptr <Platform>(new Platform(renderer, player, SDL_FPoint{ (float)newX, (float)((previousY + 75 + rand() % (201)))})));

			platforms[i]->init();*/

			generatePlatform();
		}
		
	}

	return 0;
}

void PlatformManager::generatePlatform()
{
	previousY = platforms.back().get()->collider.y;
	previousX = platforms.back().get()->collider.x;

	newX = (-250 + rand() % 501) + previousX;

	while ((newX < 0) || (newX > screenResolution::get_screenWidth() - playerDim))
	{
		newX = (-250 + rand() % 501) + previousX;
	}

	addPlat(std::unique_ptr <Platform>(new Platform(renderer, player, SDL_FPoint{ (float)newX, (float)((previousY + 75 + rand() % (151))) })));

	platforms.back()->init();
}

void PlatformManager::addPlat(std::unique_ptr<Platform> platapus)
{
	platforms.push_back(std::move(platapus));
}



void PlatformManager::scroll()
{
	for (auto& plat : platforms)
	{
		plat.get()->collider.y -= Utility::offsetY;
		//plat.get()->collider.y -= 0.025f;
	}
}



void PlatformManager::update()
{
	std::cout << score << std::endl;

	for (auto& plat : platforms)
	{
		plat->update();
		if (plat.get()->collider.y < -50)
		{
			score += 1;
			platforms.pop_front();
			generatePlatform();
			if ((int)score % 5 == 0 && Utility::offsetY < 0.5f)
			{
				Utility::offsetY += 0.0025f;
			}
		}
	}

	if (player->get_playerPos().y > 300)
	{
		Utility::startScroll = true;
	}

	if (Utility::startScroll)
	{
		scroll();
	}

}

void PlatformManager::render()
{
	for (auto& plat : platforms)
	{
		plat->render();
	}
}
