#ifndef PLAYER_H
#define PLAYER_H

#include <windows.h>
#include <vector>
#include <chrono>
#include "Point2D.h"
#include "GameObject.h"
#include "Direction.h"

using namespace std::chrono;

class Player : public GameObject
{
public:
    Player();
    void render();
    void update();
    void handleInput();

    void die();
    int getHeadX();
    int getHeadY();
    Point2D getHeadPosition();
    Direction getDirection();

    void increaseLength();

private:
    std::vector<Point2D*> m_snakePositions;
    DWORD getInput(INPUT_RECORD **eventBuffer);
    Direction moveDirection;

    bool isAlive;
    bool needToEraise;
    Point2D pointToEraise;
    bool needToIncreaseLength;
    void drawSnakeBody();
    void eraiseTailIfMoved();
};

#endif