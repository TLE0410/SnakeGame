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

class Game : public CloseEventHandler
{
public:
    void handleInput();
    void update();
    void render();
    void initialize();
    bool isGameOver();
    bool running();
    void handleCloseEvent() override;
private:
    Renderer *m_renderer_;
    Player *m_Player;
    Fruit *m_Fruit;
    Border *m_Border;
    ScoreBoard *m_ScoreBoard;
    GameOver *m_GameOver;
    bool m_isGameOver;
    CollisionManager *m_collisionManger;
    GameTimer *m_GameTimer;
    int m_Score;
    bool isGameActive;

    void printGameOver();
};

#endif
