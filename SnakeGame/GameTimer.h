#ifndef GAMETIMER_H
#define GAMETIMER_H

#include <chrono>

class GameTimer
{
public:
    GameTimer();
    bool timeToMovePlayer();
    bool timeToRender();
private:
    std::chrono::steady_clock::time_point m_lastTimePlayerMoved;
    std::chrono::steady_clock::time_point m_lastTimeImageRendered;
};

#endif
