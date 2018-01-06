#include <stdlib.h>
#include <chrono>
#include <iostream>

#include "Game.h"
#include "Fruit.h"
#include "Border.h"
#include "Player.h"
#include "Constants.h"
#include "SDLRenderingEngine.h"

using std::unique_ptr;
using std::make_unique;

void Game::update()
{
    if (m_GameTimer->timeToMovePlayer())
    {
        if (m_CollisionManger->checkPlayerAndBorderCollision(*m_Player, *m_Border)
            || m_CollisionManger->checkPlayerAndBorderCollision(*m_Player, *m_Border))
        {
            m_isGameOver = true;
        }

        if (m_CollisionManger->checkPlayerAndFruitCollision(*m_Player, *m_Fruit))
        {
            m_ScoreBoard->increaseScore();
        }

        if (m_CollisionManger->checkPlayerCollideItself(*m_Player))
        {
            //m_ScoreBoard->updateScore()
        }

        m_Player->update();
    }
}

Game::Game()
{
    m_Renderer_ = make_unique<SdlRenderingEngine>();
    m_Renderer_->addCloseEventHandler(*this);

    m_Fruit = make_unique<Fruit>(*m_Renderer_);
    m_Border = make_unique<Border>(*m_Renderer_);
    m_Player = make_unique<Player>(*m_Renderer_);
    m_Renderer_->attachMovableObserver(*m_Player);

    m_ScoreBoard = make_unique<ScoreBoard>(*m_Renderer_);
    m_GameOver = make_unique<GameOver>(*m_Renderer_);

    m_CollisionManger = make_unique<CollisionManager>();
    m_GameTimer = make_unique<GameTimer>();
}

void Game::handleInput() const
{
    m_Renderer_->pollEvents();
}
    
void Game::render()
{
    m_Renderer_->clearScreen();
    m_Border->render();
    m_Fruit->render();
    m_Player->render();
    m_ScoreBoard->render();

    if (m_isGameOver)
    {
        m_GameOver->render();
    }
    m_Renderer_->renderScreen();
}

bool Game::isGameOver() const
{
    return m_isGameOver;
}

bool Game::running() const
{
    return isGameActive;
}

void Game::handleCloseEvent()
{
    isGameActive = false;
}

void Game::printGameOver()
{
    
}