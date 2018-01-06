#include <string>
#include "Border.h"
#include "Utils.h"
#include  "Constants.h"

Border::Border(const Renderer &renderer) : GameObject(renderer)
{
    addTopHorizontalLine();
    addLeftVerticalLine();
    addRightVerticalLine();
    addBottomHorizontalLine();
}

void Border::render()
{
    Color darkBlue(0, 102, 153, 0);
    for (Point2D* point : m_borderPoints)
    {
        renderer_.renderBox(point->x, point->y, darkBlue);
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
