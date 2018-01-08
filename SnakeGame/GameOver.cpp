#include "GameOver.h"

GameOver::GameOver(Renderer& renderer) : GameObject(renderer)
{
    m_needToRender = true;
}

void GameOver::render()
{
    renderer_.renderGameOver();
}
