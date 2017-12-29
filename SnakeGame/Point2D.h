#ifndef POINT2D_H
#define POINT2D_H

struct Point2D
{
    int x;
    int y;
    bool equals(const Point2D & point)
    {
        return (this->x == point.x) && (this->y == point.y);
    }
};

#endif

