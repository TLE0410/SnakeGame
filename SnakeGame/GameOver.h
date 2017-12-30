#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "GameObject.h"

class GameOver : GameObject
{
public:
    GameOver(const Renderer &renderer);
    void render() override;
    void update() override {};
private:
    bool m_needToRender;
};

#endif
