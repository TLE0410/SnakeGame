#ifndef GAMETIMER_H
#define GAMETIMER_H

#include <chrono>

class GameTimer
{
public:
    GameTimer();
    bool timeToMovePlayer();
private:
    std::chrono::steady_clock::time_point m_lastTimePlayerMoved;
};

#endif
