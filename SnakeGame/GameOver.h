#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "GameObject.h"

class GameOver : GameObject
{
public:
    GameOver(Renderer &renderer);
    void render() override;
    void update() override {};
};

#endif
