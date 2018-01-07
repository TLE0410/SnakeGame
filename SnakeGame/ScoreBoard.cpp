#include "ScoreBoard.h"

ScoreBoard::ScoreBoard(const Renderer &renderer) : 
    GameObject(renderer), m_Score(0)
{
}

void ScoreBoard::increaseScore()
{
    m_Score++;
}

void ScoreBoard::render()
{
}
