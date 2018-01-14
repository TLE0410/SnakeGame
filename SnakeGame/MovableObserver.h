#ifndef MOVABLE_H
#define MOVABLE_H

#include "Direction.h"

class MovableObserver
{
public:
    virtual ~MovableObserver() = default;
    virtual void changeDirection(const Direction& direction) = 0;
};

#endif