#include <iostream>
#include <ostream>
#include <thread>
#include <stdio.h>
#include "Game.h"
#include <windows.h>

using namespace std;

int main()
{
    Game* game = new Game();
    game->initialize();
    system("CLS");
    while(true)
    {
        game->handleInput();
        game->update();
        game->render();
    }
    
    return 0;
}