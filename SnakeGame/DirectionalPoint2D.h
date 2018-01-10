#ifndef DIRECTIONALPOINT2D_H
#define DIRECTIONALPOINT2D_H

#include "Point2D.h"
#include "BoxDirection.h"

struct DirectionalPoint2D : Point2D
{
    DirectionalPoint2D(int x, int y, Direction direction) : Point2D(x, y), direction(direction) {};
    BoxDirection direction;
};

#endif // DIRECTIONALPOINT2D_H
