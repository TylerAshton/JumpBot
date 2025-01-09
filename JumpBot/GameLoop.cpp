#include "GameLoop.h"

bool kill;

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

	player = new Player(renderer, screenWidth, screenHeight);
	player->init();

	return 0;
}

void GameLoop::update()
{

}

void GameLoop::handleInput(SDL_Scancode& keyScanCode)
{
	switch (keyScanCode)
	{
	case SDL_SCANCODE_D:
		player->moveRight();
		break;
	case SDL_SCANCODE_A:
		player->moveLeft();
		break;
	case SDL_SCANCODE_SPACE:
		player->moveDown();
		break;
	case SDL_SCANCODE_F:
		kill = true;
		break;
	}
}

void GameLoop::render()
{
	SDL_RenderClear(renderer);
	player->render();
	SDL_RenderPresent(renderer);
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
			handleInput(userInput.key.keysym.scancode);
			return !kill;
		}
	}
	return true;
}

void GameLoop::clean()
{
	delete player;
	SDL_DestroyWindow(window);
	SDL_Quit();
}