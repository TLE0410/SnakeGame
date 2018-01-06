#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
#include "Direction.h"
#include "Point2D.h"

namespace Utils
{
    void static Log(std::string messageToLog)
    {
        std::cout << messageToLog << std::endl;
    }

    Point2D static getNextPosition(const Point2D &point, const Direction &direction)
    {
        Point2D resultPoint = point;
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
