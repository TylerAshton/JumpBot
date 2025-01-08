#include "GameLoop.h"

SDL_Window* window = nullptr;
SDL_Surface* screenSurface = nullptr;
SDL_Renderer* renderer = nullptr;

int GameLoop::init()
{

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "could not init SDL!" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return -1;
	}
	window = SDL_CreateWindow(
		"Game Window :3",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		screenWidth, screenHeight,
		SDL_WINDOW_SHOWN
	);
	if (window == NULL)
	{
		std::cout << "could not init window!" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return -1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		std::cout << "could not init renderer!" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return -1;
	}
	screenSurface = SDL_GetWindowSurface(window);

	return 0;
}

void GameLoop::update()
{

}

void GameLoop::render()
{

}

bool GameLoop::keepAlive()
{
	SDL_Event userInput;
	while (SDL_PollEvent(&userInput))
	{
		if (userInput.type == SDL_QUIT)
		{
			return false;
		}

		if (userInput.type == SDL_KEYDOWN) {
			switch (userInput.key.keysym.scancode)
			{
			case SDL_SCANCODE_F:
				break;
			default:
				break;
			}
		}
	}
	return true;
}

void GameLoop::clean()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}