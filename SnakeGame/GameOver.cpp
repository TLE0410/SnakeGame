#include "GameOver.h"

GameOver::GameOver(Renderer& renderer) : GameObject(renderer)
{
    m_needToRender = true;
}

void GameOver::render()
{
    if (m_needToRender)
    {
        //Utils::PrintText(
        //    Constants::GAME_FIELD_WIDTH_CELLS + 5, 5, "GAME OVER");
        //m_needToRender = false;
    }
}
