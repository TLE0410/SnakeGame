#include "GameState.h"

void GameState::render()
{
    if (gameState_ == LOST)
    {
        renderer_.renderGameLost();
    }
    else if (gameState_ == WON)
    {
        renderer_.renderGameWon();
    }
}

GameStateTypes GameState::getState() const
{
    return gameState_;
}

void GameState::setState(GameStateTypes gameState)
{
    gameState_ = gameState;
}
