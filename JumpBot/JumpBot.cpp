#include "GameLoop.h"

int main()
{
    
    GameLoop gameloop = GameLoop();
    if (gameloop.init() < 0)
    {
        return 1;
    }

    while (gameloop.keepAlive())
    {
        gameloop.update();
        gameloop.render();
    }

    gameloop.clean();
    return 0;
}
