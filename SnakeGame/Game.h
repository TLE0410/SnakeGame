#ifndef GAME_H
#define GAME_H

#include <memory>
#include "Border.h"
#include "CollisionManager.h"
#include "CloseEventHandler.h"
#include "Fruit.h"
#include "GameOver.h"
#include "GameTimer.h"
#include "Player.h"
#include "Renderer.h"
#include "ScoreBoard.h"

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
