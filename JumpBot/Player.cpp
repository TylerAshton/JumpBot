#include "Player.h"
#include "Time.h"

Player::Player(SDL_Renderer* sdlRenderer, int _windowWidth, int _windowHeight)
{
	renderer = sdlRenderer;
	
}

void Player::init()
{
	SDL_Surface* image = IMG_Load("Assets/player.png");
	if (image == nullptr)
	{
		std::cout << "Failed to load Image!" << std::endl;
		return;
	}
	texture = SDL_CreateTextureFromSurface(renderer, image);

	float playerWidth = 0.2f * (float)screenResolution::get_screenWidth(); // Makes playerWidth = 20% of window size

	playerRect = { ((float)screenResolution::get_screenWidth() - playerWidth) / 2, 0, playerRect.w, playerRect.h}; // Currently starts player at 0,0 (Bottom Left)

	playerRect.w = (int)playerWidth; // Just applies said changes
	playerRect.h = (int)playerWidth; // Just applies said changes

	//playerRect.y = windowHeight - playerRect.h;
}

void Player::update()
{
	const Uint8* input = SDL_GetKeyboardState(NULL);

	if (get_playerPos().y <= 0) { isGrounded = true; yVelocity = 0.0f; } else { isGrounded = false; } // :)

	if (input[SDL_Scancode::SDL_SCANCODE_SPACE] && isGrounded && alive)
	{
		moveUp();
		isGrounded = false;
	}
	if (input[SDL_Scancode::SDL_SCANCODE_A] && alive) // TODO impliment controls here
	{
		moveLeft();
		direction = SDL_FLIP_HORIZONTAL;
	}
	if (input[SDL_Scancode::SDL_SCANCODE_D] && alive)
	{
		moveRight();
		direction = SDL_FLIP_NONE;
	}

	applyGravity();
	applyVelocity();
	if (playerRect.y >= screenResolution::get_screenHeight() - 50)
	{
		playerRect.y = screenResolution::get_screenHeight() - 50;
		Player::applyGravity();
	}

	if (Utility::startScroll && isGrounded)
	{
		alive = false;
		Utility::offsetY = 0;
	}
}

void Player::render()
{
	SDL_Rect offsetRect = { playerRect.x, screenResolution::get_screenHeight() - playerRect.y - playerRect.h, playerRect.w, playerRect.h }; // Fuck you Mr Top Left!
	
	//SDL_RenderCopy(renderer, texture, NULL, &playerRect);
	SDL_RenderCopyEx(renderer, texture, NULL, &offsetRect,NULL, NULL, direction);
}

void Player::iHitSmth()
{
	Player::moveUp();
	Player::applyVelocity();
}