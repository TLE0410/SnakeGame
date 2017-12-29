#include "GameTimer.h"
#include "Constants.h"

GameTimer::GameTimer()
{
    m_lastTimePlayerMoved = std::chrono::steady_clock::now();
    m_lastTimeImageRendered = std::chrono::steady_clock::now();
}

bool GameTimer::timeToMovePlayer()
{
    auto currentTime = std::chrono::steady_clock::now();
    auto timeLag = currentTime - m_lastTimePlayerMoved;
    if (timeLag >= std::chrono::milliseconds{ Constants::SNAKE_MOVE_RATE })
    {
        m_lastTimePlayerMoved = currentTime;
        return true;
    }
    return false;
}

bool GameTimer::timeToRender()
{
    auto currentTime = std::chrono::steady_clock::now();
    auto timeLag = currentTime - m_lastTimeImageRendered;
    if (timeLag >= std::chrono::milliseconds{ Constants::REFRESH_RATE })
    {
        m_lastTimeImageRendered = currentTime;
        return true;
    }
    return false;
}
