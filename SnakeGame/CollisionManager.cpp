#include "CollisionManager.h"
#include "Utils.h"

bool CollisionManager::checkPlayerAndFruitCollision(Player & player, Fruit & fruit)
{
    Point2D headNextPosition = 
        Utils::getNextPosition(player.getHeadPosition(), player.getDirection());

    if (headNextPosition.equals(fruit.getPosition()))
    {
        player.increaseLength();
        fruit.generateNewPosition();
        return true;
    }
    return false;
}

bool CollisionManager::checkPlayerAndBorderCollision(Player & player, const Border & border)
{
    Point2D headNextPosition = Utils::getNextPosition(player.getHeadPosition(), player.getDirection());
    for (Point2D* borderPoint : border.getBorder())
    {
        if (headNextPosition.equals(*borderPoint))
        {
            player.die();
            return true;
        }
    }
    return false;
}

bool CollisionManager::checkPlayerCollideItself(Player & player)
{
    const Point2D headNextPosition = 
        Utils::getNextPosition(player.getHeadPosition(), player.getDirection());

    for (auto point = player.body_begins(); point != player.body_ends(); ++point)
    {
        if ((*point)->equals(headNextPosition))
        {
            player.removeBodyStartingWith(std::next(point));
            return true;
        }
    }
    return false;
}
