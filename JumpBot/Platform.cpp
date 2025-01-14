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
	SDL_Surface* image = IMG_Load("Assets/platform.png");
	texture = SDL_CreateTextureFromSurface(renderer, image);

	collider = { setPos.x, setPos.y, 100, 50 };

	//collider = { 0.0f, 100.0f, 100, 50};
	return 0;
}

void Platform::update()
{
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

	SDL_RenderCopyF(renderer, texture, NULL, &offsetRect);
}

void Platform::clean()
{

}