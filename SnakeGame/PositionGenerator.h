#ifndef POSITIONGENERATOR_H
#define POSITIONGENERATOR_H

#include <vector>
#include "Point2D.h"
#include "Player.h"

typedef std::vector<Point2D*>::const_iterator point_iterator;

class PositionGenerator
{
public:
    PositionGenerator(const Player& player) : player_(player) {}

    bool newPositionCollidesWithSnake(Point2D newPosition) const;
    Point2D generateNewPosition();
private:
    const Player &player_;
};

#endif