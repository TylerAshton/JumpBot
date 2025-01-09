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
		x += speed;
	}
	void moveLeft()
	{
		x -= speed;
	}

private:

	int x = 0;
	int y = 0;
	float speed = 8.0f;

	int windowWidth = 800;
	int windowHeight = 600;

	SDL_Renderer* renderer = nullptr;
	SDL_Texture* texture = nullptr;
};

