#ifndef BOXDIRECTION_H
#define BOXDIRECTION_H

#include "Direction.h"

struct BoxDirection
{
    BoxDirection(const Direction direction) : next(direction), prev(direction) {};
    void setDirection(const Direction newDirection)
    {
        prev = next;
        next = newDirection;
    }

    Direction next;
    Direction prev;
};

#endif // BOXDIRECTION_H
