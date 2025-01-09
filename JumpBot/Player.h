#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Time.h"

class Player
{
public:
	Player(SDL_Renderer* sdlRenderer, int _windowWidth, int _windowHeight);

	//double dt = Time::get_deltaTime();

	void init();
	void render();
	void update();
	void clean();

	void moveRight()
	{
		playerRect.x += speed * Time::get_deltaTime();
		if (playerRect.x + playerRect.w >= windowWidth)
		{
			playerRect.x = windowWidth - playerRect.w;
		}
	}
	void moveLeft()
	{
		playerRect.x -= speed * Time::get_deltaTime();
		if (playerRect.x <= 0)
		{
			playerRect.x = 0;
		}
	}
	void moveUp()
	{
		playerRect.y += speed * Time::get_deltaTime();
		if (playerRect.y + playerRect.h >= windowHeight)
		{
			playerRect.y = windowHeight - playerRect.h;
		}
	}

	void set_playerPos(SDL_FPoint point)
	{
		playerRect = { point.x, point.y, playerRect.w, playerRect.h };
	}

	SDL_FPoint get_playerPos()
	{
		return SDL_FPoint{ playerRect.x, playerRect.y };
	}


private:
	float speed = 248.0f;

	//SDL_Point playerPos;
	//SDL_Rect playerRect;

	//int x = portion.x;
	//int y = 600 - portion.y;

	int windowWidth = 800;
	int windowHeight = 600;

	SDL_FRect playerRect;
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* texture = nullptr;
};

