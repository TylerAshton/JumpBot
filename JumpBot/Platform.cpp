#include "Platform.h"

Platform::Platform(SDL_Renderer* sdlRenderer, Player* playerInstance, SDL_FPoint position)
{
	playerInst = playerInstance;
	renderer = sdlRenderer;
	playerRect = playerInst->get_playerRect();
	setPos = position;
}

int Platform::init()
{
	for (int i = 0; i < 8; i++)
	{
		std::string num = std::to_string(i);

		std::string filePath = "Assets/platformAnim/sprite_" + num;

		std::string fullFilePath = filePath.append(".png");

		SDL_Surface* image = IMG_Load(fullFilePath.c_str());
		texture = SDL_CreateTextureFromSurface(renderer, image);
		platformFrames.push_back(texture);
	}

	//SDL_Surface* image = IMG_Load("Assets/platform.png");
	

	collider = { setPos.x, setPos.y, 100, 50 };

	//collider = { 0.0f, 100.0f, 100, 50};
	return 0;
}

void Platform::update()
{
	if (frameNum < platformFrames.size() - 1)
	{
		frameNum += 1;
	}
	else
	{
		frameNum = 0;
	}

	checkCollider();
}

void Platform::checkCollider()
{
	SDL_FRect nullRect;

	if (SDL_IntersectFRect(playerRect, &collider, &nullRect) && playerInst->yVelocity <= 0 && playerInst->get_playerPos().y > collider.y)
	{
		playerInst->iHitSmth();
	}
}

void Platform::render()
{
	SDL_FRect offsetRect = { collider.x, screenResolution::get_screenHeight() - collider.y - collider.h, collider.w, collider.h }; // Fuck you Mr Top Left!

	SDL_Rect sourceRect = {100.0f,50.0f};

	SDL_RenderCopyF(renderer, platformFrames[frameNum], NULL, &offsetRect);
}

void Platform::clean()
{

}