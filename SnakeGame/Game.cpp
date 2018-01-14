#include "Game.h"
#include "Fruit.h"
#include "Border.h"
#include "Player.h"
#include "SDLRenderingEngine.h"
#include "Constants.h"

using std::make_unique;

void Game::update()
{
    if (gameTimer_->timeToMovePlayer())
    {
        if (collisionManger_->checkPlayerAndBorderCollision(*player_, *border_))
        {
            m_isGameOver = true;
        }

        if (collisionManger_->checkPlayerAndFruitCollision(*player_, *fruit_))
        {
            scoreBoard_->increaseScore();
        }

        if (collisionManger_->checkPlayerCollideItself(*player_))
        {
            scoreBoard_->updateScore(player_->getLength() - Constants::SNAKE_INITIAL_LENGTH);
        }

        player_->update();
    }
}

Game::Game()
{
    renderer_ = make_unique<SdlRenderingEngine>();
    renderer_->addUserInputEventHanlder(*this);
    
    player_ = make_unique<Player>(*renderer_);

    positionGenerator_ = make_unique<PositionGenerator>(*player_);

    fruit_ = make_unique<Fruit>(*renderer_, *positionGenerator_);
    border_ = make_unique<Border>(*renderer_);
    renderer_->attachMovableObserver(*player_);

    scoreBoard_ = make_unique<ScoreBoard>(*renderer_);
    gameOver_ = make_unique<GameOver>(*renderer_);

    collisionManger_ = make_unique<CollisionManager>();
    gameTimer_ = make_unique<GameTimer>();
}

void Game::handleInput() const
{
    renderer_->pollEvents();
}
    
void Game::render() const
{
    renderer_->clearScreen();
    border_->render();
    fruit_->render();
    player_->render();
    scoreBoard_->render();

    if (m_isGameOver)
    {
        gameOver_->render();
    }
    renderer_->renderScreen();
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

void Game::handleNewGameEvent()
{
    if (m_isGameOver)
    {
        gameRestart();
    }
}

void Game::gameRestart()
{
    player_->reset();
    scoreBoard_->updateScore(0);
    m_isGameOver = false;
}

