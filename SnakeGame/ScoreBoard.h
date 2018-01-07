#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "GameObject.h"
#include <vector>
#include "Point2D.h"

class ScoreBoard : GameObject
{
public:
    ScoreBoard(Renderer &renderer);
    void render() override;
    void update() override {}

    void increaseScore();
    void updateScore(int newScore);;
private:
    void updateRenderedText() const;
    std::vector<Point2D*> scoreBoard_;
    int score_;
};

#endif
