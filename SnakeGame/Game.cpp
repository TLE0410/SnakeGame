#include <stdlib.h>
#include <chrono>
#include <iostream>
#include <stdlib.h>

#include "Game.h"
#include "Fruit.h"
#include "Border.h"
#include "Player.h"
#include "Constants.h"

using namespace std::chrono;

Game::Game()
{
}

void Game::update()
{
    checkIfSnakeCollidesWithFruits();
    m_Player->update();
}

void Game::handleInput()
{
    m_Player->handleInput();
}
    
void Game::render()
{
    steady_clock::time_point current_time = steady_clock::now();

    auto duration = current_time - timeOfTheLastFrameUpdate;
    if (duration > milliseconds{ 100 })
    {
        m_Border->render();
        for (Fruit* fruit: m_Fruits)
        {
            fruit->render();
        }
        m_Player->render();

        timeOfTheLastFrameUpdate = current_time;
    }
}

void Game::initialize()
{
    Fruit* fruit = new Fruit(5, 5);
    m_Fruits.push_back(fruit);

    m_Border = new Border();
    m_Player = new Player();

    gameOver = false;

    timeOfTheLastFrameUpdate = std::chrono::steady_clock::now();
}

void Game::checkIfSnakeCollidesWithFruits()
{
    for (Fruit* fruit : m_Fruits)
    {
        if (m_Player->getHeadX() == fruit->getX()
            && m_Player->getHeadY() == fruit->getY())
        {
            int x = rand() % (Constants::GAME_FIELD_WIDTH - 2) + 2;
            int y = rand() % (Constants::GAME_FIELD_HEIGHT - 2) + 2;
            fruit->setX(x);
            fruit->setY(y);
            m_Player->increaseLength();
            break;
        }
    }
}