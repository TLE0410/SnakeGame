#include "GameState.h"

#ifdef _DEBUG
#include "Utils.h"
#endif

void GameState::render()
{
    if (gameState_ == LOST)
    {
        renderer_.renderGameLost();
#ifdef _DEBUG
        Utils::Log("You lost, sucker");
#endif
    }
    else if (gameState_ == WON)
    {
        renderer_.renderGameWon();
#ifdef _DEBUG
        Utils::Log("You won!");
#endif
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
