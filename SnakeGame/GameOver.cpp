#include "GameOver.h"

GameOver::GameOver(const Renderer& renderer) : GameObject(renderer)
{
    m_needToRender = true;
}

void GameOver::render()
{
    if (m_needToRender)
    {
        //Utils::PrintText(
        //    Constants::GAME_FIELD_WIDTH + 5, 5, "GAME OVER");
        //m_needToRender = false;
    }
}
