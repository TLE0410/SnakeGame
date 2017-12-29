#include "CollisionManager.h"
#include "Utils.h"

void CollisionManager::checkPlayerAndFruitCollision(Player & player, Fruit & fruit)
{
    // get a point where player is going to be
    Point2D headNextPosition = Utils::getNextPosition(player.getHeadPosition(), player.getDirection());
    if (headNextPosition.equals(fruit.getPosition()))
    {
        player.increaseLength();
        fruit.generateNewPosition();
    }
}

void CollisionManager::checkPlayerAndBorderCollision(Player & player, Border & border)
{
    Point2D headNextPosition = Utils::getNextPosition(player.getHeadPosition(), player.getDirection());
    for (Point2D* borderPoint : border)

}

void CollisionManager::checkPlayerCollideItself(Player & player)
{
}
