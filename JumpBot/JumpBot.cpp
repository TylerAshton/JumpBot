#include <iostream>
#include <string>

#define SDL_MAIN_HANDLED
#include <SDL.h>

const int screenWidth = 800;
const int screenHeight = 600;

int main()
{
    SDL_Window* window = nullptr;
    SDL_Surface* screenSurface = nullptr;

    if (SDL:_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "coul;d not initialize SDL2!" << std::endl;
        std::cout << SDL_GetError() << std::endl;
        return 1;
    }
    window = SDL_CreateWindow(
        "Hello_SDL2", // Title
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, //X and Y of Position
        screenWidth, screenHeight //Width and Height - This was defined as a constant at the start of the script
        SDL_WINDOW_SHOWN
    );
    if (window == NULL) {
        std::cout << "Could not initialize window!" << std::endl;
        std::cout << SDL_GetError() << std::endl;
        return 1;
    }
    screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 144, 238, 144));
    SDL_UpdateWindowSurface(window);
    SDL_Delay(2000);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
