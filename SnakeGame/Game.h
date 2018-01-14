#ifndef GAME_H
#define GAME_H

#include <memory>
#include "Border.h"
#include "CollisionManager.h"
#include "UserInputEventHandler.h"
#include "Fruit.h"
#include "GameOver.h"
#include "GameTimer.h"
#include "Player.h"
#include "Renderer.h"
#include "ScoreBoard.h"

using std::unique_ptr;

class Game : public UserInputEventHandler
{
public:
    Game();
    void handleInput() const;
    void update();
    void render() const;
    bool isGameOver() const;
    bool running() const;
    void handleCloseEvent() override;
    void handleNewGameEvent() override;
private:
    void gameRestart();

    unique_ptr<Renderer> renderer_;
    unique_ptr<Player> player_;
    unique_ptr<Fruit> fruit_;
    unique_ptr<Border> border_;
    unique_ptr<ScoreBoard> scoreBoard_;
    unique_ptr<GameOver> gameOver_;
    unique_ptr<CollisionManager> collisionManger_;
    unique_ptr<PositionGenerator> positionGenerator_;

    unique_ptr<GameTimer> gameTimer_;

    bool isGameActive = true;
    bool m_isGameOver = false;
};

#endif
