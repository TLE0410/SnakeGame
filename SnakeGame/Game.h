#ifndef GAME_H
#define GAME_H

#include "Renderer.h"
#include "Player.h"
#include "Fruit.h"
#include "Border.h"
#include "CollisionManager.h"
#include "GameTimer.h"
#include "ScoreBoard.h"
#include "GameOver.h"
#include "CloseEventHandler.h"
#include <memory>

using std::unique_ptr;

class Game : public CloseEventHandler
{
public:
    Game();
    void handleInput() const;
    void update();
    void render();
    bool isGameOver() const;
    bool running() const;
    void handleCloseEvent() override;
private:
    unique_ptr<Renderer> m_Renderer_;
    unique_ptr<Player> m_Player;
    unique_ptr<Fruit> m_Fruit;
    unique_ptr<Border> m_Border;
    unique_ptr<ScoreBoard> m_ScoreBoard;
    unique_ptr<GameOver> m_GameOver;
    unique_ptr<CollisionManager> m_CollisionManger;

    unique_ptr<GameTimer> m_GameTimer;
    int m_Score;

    bool isGameActive = true;
    bool m_isGameOver = false;

    void printGameOver();
};

#endif
