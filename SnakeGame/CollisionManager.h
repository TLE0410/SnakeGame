#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "Player.h"
#include "Fruit.h"
#include "Border.h"

class CollisionManager
{
public:
    void checkPlayerAndFruitCollision(Player& player, Fruit& fruit);
    void checkPlayerAndBorderCollision(Player& player, Border& border);
    void checkPlayerCollideItself(Player& player);
};

#endif
