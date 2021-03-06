#include <string>
#include "Border.h"
#include "Utils.h"
#include  "Constants.h"

Border::Border(Renderer &renderer) : GameObject(renderer)
{
    addTopHorizontalLine();
    addLeftVerticalLine();
    addRightVerticalLine();
    addBottomHorizontalLine();
}

void Border::render()
{
    // border_ is outside of the game field, nothing to draw
}

const std::vector<Point2D*> Border::getBorder() const
{
    return m_borderPoints;
}

void Border::addTopHorizontalLine()
{
    for (int i = 1; i <= Constants::GAME_FIELD_WIDTH_CELLS; i++)
    {
        Point2D* p = new Point2D;
        p->x = i;
        p->y = 0;
        m_borderPoints.push_back(p);
    }
}

void Border::addLeftVerticalLine()
{
    for (int i = 1; i <= Constants::GAME_FIELD_HEIGHT_CELLS; i++)
    {
        Point2D* p = new Point2D;
        p->x = 0;
        p->y = i;
        m_borderPoints.push_back(p);
    }
}

void Border::addRightVerticalLine()
{
    for (int i = 1; i <= Constants::GAME_FIELD_HEIGHT_CELLS; i++)
    {
        Point2D* p = new Point2D;
        p->x = Constants::GAME_FIELD_WIDTH_CELLS + 1;
        p->y = i;
        m_borderPoints.push_back(p);
    }
}

void Border::addBottomHorizontalLine()
{
    for (int i = 1; i <= Constants::GAME_FIELD_WIDTH_CELLS; i++)
    {
        Point2D* p = new Point2D();
        p->x = i;
        p->y = Constants::GAME_FIELD_HEIGHT_CELLS + 1;
        m_borderPoints.push_back(p);
    }
}
