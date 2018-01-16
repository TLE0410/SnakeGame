#ifndef RENDERINGENGINE_H
#define RENDERINGENGINE_H

#include <string>
#include "MovableObserver.h"
#include "UserInputEventHandler.h"
#include "Color.h"
#include "Point2D.h"
#include "DirectionalPoint2D.h"
#include "SnakeBodyPart.h"

class Renderer
{
public:
    virtual ~Renderer() = default;
    virtual void pollEvents() = 0;
    virtual void addUserInputEventHanlder(UserInputEventHandler &closeEventHandler) = 0;
    virtual void attachMovableObserver(MovableObserver &movableObserver) = 0;
    virtual void clearScreen() = 0;
    virtual void renderScreen() = 0;
    virtual void renderBox(Point2D point, Color color) const = 0;
    virtual void renderBox(int x, int y, int width, int height, Color color) const = 0;
    virtual void setText(const std::string textToRender) = 0;
    virtual void renderText() = 0;
    virtual void renderGameLost() const = 0;
    virtual void renderGameWon() const = 0;

    virtual void renderSnakeBox(DirectionalPoint2D point, SnakeBodyPart bodyPart) const = 0;
    virtual void renderFruitBox(Point2D point) const = 0;
};

#endif // RENDERINGENGINE_H