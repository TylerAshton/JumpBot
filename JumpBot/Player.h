#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Player
{
public:
	Player(SDL_Renderer* sdlRenderer, int _windowWidth, int _windowHeight);

	void init();
	void render();
	void update();
	void clean();

	void moveRight()
	{
		portion.x += speed;
		if (portion.x + portion.w >= windowWidth)
		{
			portion.x = windowWidth - portion.w;
		}
	}
	void moveLeft()
	{
		portion.x -= speed;
		if (portion.x <= 0)
		{
			portion.x = 0;
		}
	}
	void moveDown()
	{
		portion.y += speed;
		if (portion.y + portion.h >= windowHeight)
		{
			portion.y = windowHeight - portion.h;
		}
	}

private:
	float speed = 8.0f;

	int x = portion.x;
	int y = 600 - portion.y;

	int windowWidth = 800;
	int windowHeight = 600;

	SDL_Rect portion;
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* texture = nullptr;
};

