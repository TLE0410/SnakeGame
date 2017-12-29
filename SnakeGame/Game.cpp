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
    //CllicheckIfSnakeCollidesWithFruits();
    collisionManger->checkPlayerAndFruitCollision(*m_Player, *m_Fruit);
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
        m_Fruit->render();
        m_Player->render();

        timeOfTheLastFrameUpdate = current_time;
    }
}

void Game::initialize()
{
    m_Fruit = new Fruit();
    m_Border = new Border();
    m_Player = new Player();

    gameOver = false;

    timeOfTheLastFrameUpdate = std::chrono::steady_clock::now();
    collisionManger = new CollisionManager();
}
