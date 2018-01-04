#ifndef RENDERINGENGINE_H
#define RENDERINGENGINE_H

#include "MovableObserver.h"
#include "CloseEventHandler.h"

class Renderer
{
public:
    virtual ~Renderer() = default;
    virtual void pollEvents() = 0;
    virtual void addCloseEventHandler(CloseEventHandler &closeEventHandler) = 0;
    virtual void attachMovableObserver(MovableObserver &movableObserver) = 0;
    virtual void clearScreen() = 0;
    virtual void renderScreen() = 0;
    virtual void renderBox(int x, int y, int color) const = 0;
};

#endif // RENDERINGENGINE_H