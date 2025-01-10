#include "Player.h"
#include "Time.h"

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

	playerRect = { 0, 0, playerRect.w, playerRect.h }; // Currently starts player at 0,0 (Bottom Left)

	float playerWidth = 0.2f * (float)screenResolution::get_screenWidth(); // Makes playerWidth = 20% of window size
	playerRect.w = (int)playerWidth; // Just applies said changes
	playerRect.h = (int)playerWidth; // Just applies said changes

	//playerRect.y = windowHeight - playerRect.h;
}

void Player::update()
{
	const Uint8* input = SDL_GetKeyboardState(NULL);

	if (get_playerPos().y <= 0) { isGrounded = true; yVelocity = 0.0f; } else { isGrounded = false; } // :)

	if (input[SDL_Scancode::SDL_SCANCODE_SPACE] && isGrounded)
	{
		moveUp();
		isGrounded = false;
	}
	if (input[SDL_Scancode::SDL_SCANCODE_A]) // TODO impliment controls here
	{
		moveLeft();
	}
	if (input[SDL_Scancode::SDL_SCANCODE_D])
	{
		moveRight();
	}

	applyGravity();
	applyVelocity();
	if (playerRect.y >= screenResolution::get_screenHeight())
	{
		playerRect.y = screenResolution::get_screenHeight();
	}
}

void Player::render()
{
	SDL_Rect offsetRect = { playerRect.x, screenResolution::get_screenHeight() - playerRect.y - playerRect.h, playerRect.w, playerRect.h }; // Fuck you Mr Top Left!
	
	//SDL_RenderCopy(renderer, texture, NULL, &playerRect);
	SDL_RenderCopy(renderer, texture, NULL, &offsetRect);
}