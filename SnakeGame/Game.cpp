#include <stdlib.h>
#include <chrono>
#include <iostream>

#include "Game.h"
#include "Fruit.h"
#include "Border.h"
#include "Player.h"
#include "Constants.h"
#include "SDLRenderingEngine.h"

void Game::update()
{
    if (m_GameTimer->timeToMovePlayer())
    {
        if (m_collisionManger->checkPlayerAndBorderCollision(*m_Player, *m_Border)
            || m_collisionManger->checkPlayerAndBorderCollision(*m_Player, *m_Border))
        {
            m_isGameOver = true;
        }

        if (m_collisionManger->checkPlayerAndFruitCollision(*m_Player, *m_Fruit))
        {
            m_ScoreBoard->increaseScore();
        }

        m_Player->update();
    }
}

void Game::handleInput()
{
    m_renderer_->pollEvents();
}
    
void Game::render()
{
    if (m_GameTimer->timeToRender())
    {
        m_Border->render();
        m_Fruit->render();
        m_Player->render();
        m_ScoreBoard->render();
    }

    if (m_isGameOver)
    {
        m_GameOver->render();
    }
}

void Game::initialize()
{
    m_renderer_ = new SdlRenderingEngine();

    m_Fruit = new Fruit(*m_renderer_);
    m_Border = new Border(*m_renderer_);
    m_Player = new Player(*m_renderer_);
    m_renderer_->attachMovableObserver(*m_Player);

    m_ScoreBoard = new ScoreBoard(*m_renderer_);
    m_GameOver = new GameOver(*m_renderer_);

    m_collisionManger = new CollisionManager();
    m_GameTimer = new GameTimer();
    m_isGameOver = false;
}


bool Game::isGameOver()
{
    return m_isGameOver;
}

void Game::printGameOver()
{
    
}
