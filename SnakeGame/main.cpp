#include "Game.h"

int main()
{
    std::unique_ptr<Game> game = std::make_unique<Game>();
    
    while(game->running())
    {
        game->handleInput();
        game->update();
        game->render();
    }

    return 0;
}


