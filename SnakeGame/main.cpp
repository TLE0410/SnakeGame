#include <stdio.h>
#include "Game.h"

int main()
{
    Game* game = new Game();
    game->initialize();

    while(game->running())
    {
        game->handleInput();
        game->update();
        game->render();
    }

    return 0;
}


