#include "ScoreBoard.h"
#include "Constants.h"
#include <string>

ScoreBoard::ScoreBoard(Renderer &renderer) : 
    GameObject(renderer), score_(0)
{
    updateRenderedText();
}

void ScoreBoard::updateRenderedText() const
{
    renderer_.setText("score " + std::to_string(score_));
}

void ScoreBoard::increaseScore()
{
    score_++;
    updateRenderedText();
}

void ScoreBoard::render()
{
    using namespace Constants;
    const Color yellow(255, 153, 51, 200);
    renderer_.renderBox(
        1, GAME_FIELD_HEIGHT_CELLS + 1,
        GAME_FIELD_WIDTH_CELLS,
        2,
        yellow);

    renderer_.renderText();
}

void ScoreBoard::updateScore(int newScore)
{
    score_ = newScore;
    updateRenderedText();
}
