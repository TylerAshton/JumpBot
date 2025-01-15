#include "FontRenderer.h"

FontRenderer::FontRenderer(SDL_Renderer* sdlRenderer)
{
	renderer = sdlRenderer;
}
void FontRenderer::init()
{
	int init = TTF_Init();
	if (init != 0)
	{
		std::cout << SDL_GetError() << std::endl;
	}
	font = TTF_OpenFont("Assets/FFF_Tusj.ttf", 500);
	if (font == NULL)
	{
		std::cout << SDL_GetError() << std::endl;
	}
}
void FontRenderer::clean()
{
	TTF_CloseFont(font);
}
void FontRenderer::render(std::string text)
{
	SDL_Rect renderRect =
	{
		0,
		400,
		500,
		100
	};

	SDL_Color colour = SDL_Color();
	colour.r = 255;
	colour.g = 0;
	colour.b = 0;
	colour.a = 255;

	SDL_Surface* textImage = TTF_RenderText_Solid(font, text.c_str(), colour);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textImage);
	SDL_RenderCopy(renderer, texture, NULL, &renderRect);

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(textImage);
}