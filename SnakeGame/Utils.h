#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "Constants.h"
#include "Direction.h"
#include "Point2D.h"

namespace Utils
{
    void static PrintText(int x, int y, std::string text)
    {
        printf("\033[%d;%dH%s", y + 2, x + 5, text.c_str());
    }

    void static Log(std::string messageToLog)
    {
        PrintText(5, Constants::GAME_FIELD_WIDTH + 2, messageToLog.c_str());
    }

    Point2D static getNextPosition(const Point2D &point, const Direction &direction)
    {
        Point2D resultPoint;
        resultPoint = point;
        switch (direction)
        {
            case up:
            {
                resultPoint.y--;
                break;
            }
            case right:
            {
                resultPoint.x++;
                break;
            }
            case down:
            {
                resultPoint.y++;
                break;
            }
            case left:
            {
                resultPoint.x--;
                break;
            }
        }
        return resultPoint;
    }
}

#endif
