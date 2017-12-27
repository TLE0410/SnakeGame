#ifndef GAME_H
#define GAME_H

#include <vector>
#include <chrono>
#include <ctime>
#include "Player.h"
#include "Fruit.h"
#include "Border.h"

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
    std::vector<Fruit*> m_Fruits;
    Border* m_Border;
    std::chrono::steady_clock::time_point timeOfTheLastFrameUpdate;
    bool gameOver;
    void checkIfSnakeCollidesWithFruits();
    bool snakeWillCollideWithItself();
    bool snakeWillCollideWithWall();
};

#endif
