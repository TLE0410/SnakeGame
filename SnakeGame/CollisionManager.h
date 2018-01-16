#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "Player.h"
#include "Fruit.h"
#include "Border.h"

class CollisionManager
{
public:
    bool checkPlayerAndFruitCollision(const Player& player, const Fruit& fruit) const;
    bool checkPlayerAndBorderCollision(Player& player, const Border& border) const;
    bool checkPlayerCollideItself(Player& player) const;
};

#endif