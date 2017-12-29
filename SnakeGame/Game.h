#ifndef GAME_H
#define GAME_H

#include <vector>
#include <chrono>
#include <ctime>
#include "Player.h"
#include "Fruit.h"
#include "Border.h"
#include "CollisionManager.h"

class Game
{
public:
    Game();
    void handleInput();
    void update();
    void render();
    void initialize();
private:
    Player* m_Player;
    Fruit* m_Fruit;
    Border* m_Border;
    std::chrono::steady_clock::time_point timeOfTheLastFrameUpdate;
    bool gameOver;
    CollisionManager* collisionManger;
};

#endif
