#include "GameLoop.h"

bool alive;

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
		screenResolution::get_screenWidth(), screenResolution::get_screenHeight(),
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

	platMan = new PlatformManager();

	player = new Player(renderer, screenResolution::get_screenWidth(), screenResolution::get_screenHeight());
	player->init();

	tiledMap = std::unique_ptr<TiledMap>(new TiledMap(renderer, "Assets/tmss.png"));
	tiledMap->init();

	platform = std::unique_ptr <Platform>(new Platform(renderer, player, SDL_FPoint{0,100}));
	platform->init();

	platMan->platforms.push_back(std::move(platform));

	platform1 = std::unique_ptr <Platform>(new Platform(renderer, player, SDL_FPoint{ 200,200}));
	platform1->init();

	platMan->platforms.push_back(std::move(platform1));

	platform2 = std::unique_ptr <Platform>(new Platform(renderer, player, SDL_FPoint{ 350,400 }));
	platform2->init();

	platMan->platforms.push_back(std::move(platform2));

	//platMan->addPlat(platform);

	return 0;
}

void GameLoop::update()
{
	platMan->update();
	//platform->update();
	player->update();
}

//void GameLoop::handleInput(SDL_Scancode& keyScanCode)
//{
//	if ()
//	{
//		player->moveRight();
//	}
//	if (SDL_SCANCODE_A)
//	{
//		player->moveLeft();
//	}
//	if (SDL_SCANCODE_SPACE)
//	{
//		player->moveUp();
//	}
//	if (SDL_SCANCODE_F)
//	{
//		alive = true;
//	}
//
//	/*switch (keyScanCode)
//	{
//	case SDL_SCANCODE_D:
//		player->moveRight();
//		break;
//	case SDL_SCANCODE_A:
//		player->moveLeft();
//		break;
//	case SDL_SCANCODE_SPACE:
//		player->moveUp();
//		break;
//	case SDL_SCANCODE_F:
//		kill = true;
//		break;
//	}*/
//}

void GameLoop::render()
{
	SDL_RenderClear(renderer);
	
	tiledMap->render();
	platMan->render();
	//platform->render();
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

		if (userInput.type == SDL_KEYDOWN)
		{
			if (userInput.type == SDL_KEYDOWN) {
				switch (userInput.key.keysym.scancode)
				{
				case SDL_SCANCODE_F:
					return false;
					break;
				default:
					break;
				}
			}

			/*handleInput(userInput.key.keysym.scancode);
			return !alive;*/
		}
	}
	return true;
}

void GameLoop::clean()
{
	tiledMap->clean();

	delete player;
	SDL_DestroyWindow(window);
	SDL_Quit();
}