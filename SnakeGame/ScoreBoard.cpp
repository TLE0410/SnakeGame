#include "ScoreBoard.h"
#include "Utils.h"
#include "Constants.h"

ScoreBoard::ScoreBoard()
{
    m_Score = 0;
    m_NeedToRenderScore = true;
}

void ScoreBoard::increaseScore()
{
    m_Score++;
    m_NeedToRenderScore = true;
}

void ScoreBoard::render()
{
    if (m_NeedToRenderScore)
    {
        std::string scoreToPrint = "Score: " + std::to_string(m_Score);
        Utils::PrintText(2, Constants::GAME_FIELD_HEIGHT + 2, scoreToPrint);
        m_NeedToRenderScore = false;
    }
}
