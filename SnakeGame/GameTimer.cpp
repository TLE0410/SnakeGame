#include "GameTimer.h"
#include "Constants.h"

GameTimer::GameTimer()
{
    m_lastTimePlayerMoved = std::chrono::steady_clock::now();
}

bool GameTimer::timeToMovePlayer()
{
    const auto currentTime = std::chrono::steady_clock::now();
    const auto timeLag = currentTime - m_lastTimePlayerMoved;
    if (timeLag >= std::chrono::milliseconds{ Constants::SNAKE_MOVE_RATE })
    {
        m_lastTimePlayerMoved = currentTime;
        return true;
    }
    return false;
}