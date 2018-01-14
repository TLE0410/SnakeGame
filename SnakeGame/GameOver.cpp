#include "GameOver.h"

GameOver::GameOver(Renderer& renderer) : GameObject(renderer)
{
}

void GameOver::render()
{
    renderer_.renderGameOver();
}
