#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Time.h"
#include "screenResolution.h"
#include "Utility.h"

class Player
{
public:
	Player(SDL_Renderer* sdlRenderer, int _windowWidth, int _windowHeight);

	float yVelocity;

	//double dt = Time::get_deltaTime();

	void init();
	void render();
	void update();
	void clean();

	void iHitSmth();

	void moveRight()
	{
		playerRect.x += speed.x * Time::get_deltaTime();
		if (playerRect.x + playerRect.w >= screenResolution::get_screenWidth())
		{
			playerRect.x = screenResolution::get_screenWidth() - playerRect.w;
		}
	}
	void moveLeft()
	{
		playerRect.x -= speed.x * Time::get_deltaTime();
		if (playerRect.x <= 0)
		{
			playerRect.x = 0;
		}
	}
	void moveUp()
	{
		//playerRect.y += speed * Time::get_deltaTime();

		yVelocity = speed.y;
	}

	void applyGravity()
	{
		SDL_FPoint currentPos = get_playerPos();
		if (currentPos.y > 0) {
			yVelocity += gravity;
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
	
	void applyVelocity() {
		set_playerPos(SDL_FPoint{ get_playerPos().x , get_playerPos().y + (float)(yVelocity * Time::get_deltaTime())});
	}

	SDL_FRect* get_playerRect()
	{
		return &playerRect;
	}

private:
	bool isGrounded;

	bool alive = true;

	float gravity = -1.0f;
	SDL_FPoint speed = { 248.0f, 1250.0f };

	SDL_RendererFlip direction = SDL_FLIP_NONE;

	//SDL_Point playerPos;
	//SDL_Rect playerRect;

	//int x = portion.x;
	//int y = 600 - portion.y;

	SDL_FRect playerRect;
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* texture = nullptr;
};

