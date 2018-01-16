#include "CollisionManager.h"
#include "Utils.h"

bool CollisionManager::checkPlayerAndFruitCollision(const Player& player, const Fruit& fruit) const
{
    DirectionalPoint2D headNextPosition = 
        Utils::getNextPosition(player.getHeadPosition(), player.getDirection());

    if (headNextPosition.equals(fruit.getPosition()))
    {
        return true;
    }
    return false;
}

bool CollisionManager::checkPlayerAndBorderCollision(Player & player, const Border & border) const
{
    DirectionalPoint2D headNextPosition = Utils::getNextPosition(player.getHeadPosition(), player.getDirection());
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

bool CollisionManager::checkPlayerCollideItself(Player & player) const
{
    const DirectionalPoint2D headNextPosition = 
        Utils::getNextPosition(player.getHeadPosition(), player.getDirection());

    for (auto point = player.body_begins(); point != player.body_ends(); ++point)
    {
        if (headNextPosition.equals(**point))
        {
            player.removeBodyStartingWith(std::next(point));
            return true;
        }
    }
    return false;
}
