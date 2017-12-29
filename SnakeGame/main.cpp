#include <iostream>
#include <ostream>
#include <thread>
#include <stdio.h>
#include "Game.h"
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include "Constants.h"

using namespace std;

void cleanConsoleScreen();

int main()
{
    cleanConsoleScreen();

    Game* game = new Game();
    game->initialize();

    while(true)
    {
        game->handleInput();
        game->update();
        game->render();
    }

    return 0;
}

void cleanConsoleScreen()
{
    system("CLS");
}
