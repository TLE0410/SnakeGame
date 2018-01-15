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
    renderer_.renderFruitBox(position_);
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
