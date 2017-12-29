#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "GameObject.h"

class GameOver : GameObject
{
public:
    GameOver();
    void render();
    void update() {};
    void handleInput() {};
private:
    bool m_needToRender;
};

#endif
