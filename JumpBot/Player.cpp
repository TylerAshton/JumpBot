#include "Player.h"

Player::Player(SDL_Renderer* sdlRenderer, int _windowWidth, int _windowHeight)
{
	renderer = sdlRenderer;
}

void Player::init()
{
	SDL_Surface* image = IMG_Load("Assets/TestImage.png");
	if (image == nullptr)
	{
		std::cout << "Failed to load Image!" << std::endl;
		return;
	}
	texture = SDL_CreateTextureFromSurface(renderer, image);
}

void Player::render()
{
	SDL_Rect portion = SDL_Rect();
	portion.x = x;
	portion.y = y;

	float playerWidth = 0.2f * (float)windowWidth;
	portion.w = (int)playerWidth;
	portion.h = (int)playerWidth;

	SDL_RenderCopy(renderer, texture, NULL, &portion);
}