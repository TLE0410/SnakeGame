#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "Player.h"
#include "Fruit.h"
#include "Border.h"

class CollisionManager
{
public:
    bool checkPlayerAndFruitCollision(Player& player, Fruit& fruit);
    bool checkPlayerAndBorderCollision(Player& player, const Border& border);
    bool checkPlayerCollideItself(Player& player);
};

#endif
