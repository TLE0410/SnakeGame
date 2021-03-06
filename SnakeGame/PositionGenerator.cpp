#include "Point2D.h"
#include "PositionGenerator.h"
#include "Utils.h"
#include "Constants.h"

bool PositionGenerator::newPositionCollidesWithSnake(Point2D newPosition) const
{
    DirectionalPoint2D headNextPosition =
         Utils::getNextPosition(player_.getHeadPosition(), player_.getDirection());
    
    if (headNextPosition.equals(newPosition))
    {
        return true;
    }

    for (auto point = player_.body_begins(); point != player_.body_ends(); ++point)
    {
        if ((*point)->equals(newPosition))
        {
            return true;
        }
    }

    return  false;
}

Point2D PositionGenerator::generateNewPosition() const
{
    Point2D newPosition;

    while (true)
    {
        newPosition.x = rand() % Constants::GAME_FIELD_WIDTH_CELLS + 1;
        newPosition.y = rand() % Constants::GAME_FIELD_HEIGHT_CELLS +1;

        if (!newPositionCollidesWithSnake(newPosition))
        {
            break;
        }
    }

    return newPosition;
}
