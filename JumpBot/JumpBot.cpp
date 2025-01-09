#include "GameLoop.h"
#include "Time.h"

int main()
{
    
    GameLoop gameloop = GameLoop();
    if (gameloop.init() < 0)
    {
        return 1;
    }

    while (gameloop.keepAlive())
    {
        Time::UpdateDeltaTime();
        gameloop.update();
        gameloop.render();
    }

    gameloop.clean();
    return 0;
}
