#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "GameObject.h"

class ScoreBoard : GameObject
{
public:
    ScoreBoard(const Renderer &renderer);
    void increaseScore();

    void render() override;
    void update() override {};

private:
    int m_Score;
    bool m_NeedToRenderScore;
};

#endif
