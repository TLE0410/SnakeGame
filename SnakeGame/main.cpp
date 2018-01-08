#include "Game.h"
#include "SDL_main.h"

extern "C" { FILE __iob_func[3] = { *stdin,*stdout,*stderr }; }
#pragma comment(lib, "legacy_stdio_definitions.lib") 

int main(int argc, char *args[])
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


