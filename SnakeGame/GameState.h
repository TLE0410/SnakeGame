#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "GameObject.h"

enum GameStateTypes
{
    IN_PROGRESS,
    WON,
    LOST
};

class GameState : public GameObject
{
public:
    GameState(Renderer &renderer) : GameObject(renderer), gameState_(IN_PROGRESS) {}
    void render() override;
    void update() override {};

    GameStateTypes getState() const;
    void setState(GameStateTypes gameState);

private:
    GameStateTypes gameState_;
};

#endif
