#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Time.h"
#include "Player.h"
#include "Utility.h"
#include <vector>
#include <string>

class Platform
{
public:
	Platform(SDL_Renderer* sdlRenderer, Player* playerInst, SDL_FPoint position);
	
	int init();
	void update();
	void render();
	void clean();

	void checkCollider();
	SDL_FRect collider;
private:
	std::vector<SDL_Texture*> platformFrames = {};

	int frameNum = 0;

	SDL_Renderer* renderer = nullptr;
	SDL_Texture* texture = nullptr;
	SDL_FRect* playerRect;

	Player* playerInst;

	SDL_FPoint setPos;
};

