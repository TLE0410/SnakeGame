#ifndef DIRECTIONALPOINT2D_H
#define DIRECTIONALPOINT2D_H

#include "Point2D.h"
#include "Direction.h"

struct DirectionalPoint2D : Point2D
{
    DirectionalPoint2D(int x, int y, Direction direction) : Point2D(x, y), direction(direction) {};
    Direction direction;
};

#endif // DIRECTIONALPOINT2D_H
