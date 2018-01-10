#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
#include "Point2D.h"
#include "DirectionalPoint2D.h"

namespace Utils
{
    void static Log(std::string messageToLog)
    {
        std::cout << messageToLog << std::endl;
    }

    inline DirectionalPoint2D getNextPosition(const DirectionalPoint2D &point, const Direction &direction)
    {
        DirectionalPoint2D resultPoint = point;
        resultPoint.direction.next = direction;
        resultPoint.direction.prev = direction;

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
