#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "GameObject.h"

class ScoreBoard : GameObject
{
public:
    ScoreBoard(const Renderer &renderer);
    void increaseScore();

    void render();
    void update() {};
    void handleInput() {};

private:
    int m_Score;
    bool m_NeedToRenderScore;
};

#endif
