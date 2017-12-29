#include "Border.h"
#include "Utils.h"
#include <string>

Border::Border()
{
    addTopHorizontalLine();
    addLeftVerticalLine();
    addRightVerticalLine();
    addBottomHorizontalLine();
}

void Border::render()
{
    std::string borderPixel;
    borderPixel = (char)219;
    for (Point2D* point : m_borderPoints)
    {
        Utils::PrintText(point->x, point->y, borderPixel);
    }
}

const std::vector<Point2D*> Border::getBorder() const
{
    return m_borderPoints;
}

void Border::addTopHorizontalLine()
{
    for (int i = 1; i <= Constants::GAME_FIELD_WIDTH; i++)
    {
        Point2D* p = new Point2D;
        p->x = i;
        p->y = 1;
        m_borderPoints.push_back(p);
    }
}

void Border::addLeftVerticalLine()
{
    for (int i = 2; i <= Constants::GAME_FIELD_HEIGHT - 1; i++)
    {
        Point2D* p = new Point2D;
        p->x = 1;
        p->y = i;
        m_borderPoints.push_back(p);
    }
}

void Border::addRightVerticalLine()
{
    for (int i = 2; i <= Constants::GAME_FIELD_HEIGHT - 1; i++)
    {
        Point2D* p = new Point2D;
        p->x = Constants::GAME_FIELD_WIDTH;
        p->y = i;
        m_borderPoints.push_back(p);
    }
}

void Border::addBottomHorizontalLine()
{
    for (int i = 1; i <= Constants::GAME_FIELD_WIDTH; i++)
    {
        Point2D* p = new Point2D();
        p->x = i;
        p->y = Constants::GAME_FIELD_HEIGHT;
        m_borderPoints.push_back(p);
    }
}
