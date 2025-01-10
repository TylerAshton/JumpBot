#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

const int mapWidth = 6;
const int mapHeight = 7;
const int map[mapHeight][mapWidth] = {
	{1, 2, 3, 4, 5, 6},
	{7, 8, 9, 10, 11, 12},
	{13, 14, 15, 16, 17, 18},
	{19, 20, 21, 22, 23, 24},
	{25, 26, 27, 28, 29, 30},
	{31, 32, 33, 34, 35, 36},
	{37, 38, 39, 40, 41, 42}
};

class TiledMap
{
public:
	TiledMap(SDL_Renderer* sdlRenderer, std::string tiledMapFilename);

	int init();
	void render();
	void clean();

private:

	const int sourceTileSizePx = 70;
	const int tileWidth = 70;
	const int tileHeight = 70;

	std::string filename;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
};

