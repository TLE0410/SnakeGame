#include "Fruit.h"
#include "Utils.h"


Fruit::Fruit(Renderer& renderingEngine, PositionGenerator& positionGenerator) :
    GameObject(renderingEngine),
    positionGenerator_(positionGenerator)
{
    generateRandomPosition();
}

void Fruit::render()
{
    const Color greenColor(255, 0, 0, 200);
    renderer_.renderBox(position_.x, position_.y, greenColor);
}

void Fruit::update()
{
}

Point2D Fruit::getPosition() const
{
    return position_;
}

void Fruit::generateNewPosition()
{
    generateRandomPosition();
}

void Fruit::generateRandomPosition()
{
    position_ = positionGenerator_.generateNewPosition();
}
