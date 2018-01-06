#include "Point2D.h"
#include "PositionGenerator.h"
#include "Utils.h"
#include "Constants.h"

bool PositionGenerator::newPositionCollidesWithSnake(Point2D newPosition) const
{
    for (auto point = player_.body_begins(); point != player_.body_ends(); ++point)
    {
        if ((*point)->equals(newPosition))
        {
            return true;
        }
    }
    return  false;
}

Point2D PositionGenerator::generateNewPosition()
{
    bool positionOccupied = false;
    Point2D newPosition;

    while (true)
    {
        newPosition.x = rand() % (Constants::GAME_FIELD_WIDTH - 2) + 2;
        newPosition.y = rand() % (Constants::GAME_FIELD_HEIGHT - 2) + 2;

        Utils::Log(std::to_string(newPosition.x) + " " + std::to_string(newPosition.y));

        if (!newPositionCollidesWithSnake(newPosition))
        {
            break;
        }
    }

    return newPosition;
}