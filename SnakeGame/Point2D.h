#ifndef POINT2D_H
#define POINT2D_H

struct Point2D
{
    Point2D(int x, int y) : x(x), y(y) {}
    Point2D() : Point2D(0, 0) {};
    int x;
    int y;
    bool equals(const Point2D & point) const
    {
        return (this->x == point.x) && (this->y == point.y);
    }
};

#endif

