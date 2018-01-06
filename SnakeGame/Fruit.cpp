#include <string>
#include "Fruit.h"
#include "Utils.h"
#include "Constants.h"

Fruit::Fruit(const Renderer &renderingEngine) : GameObject(renderingEngine)
{
    generateRandomPosition();
}

void Fruit::render()
{
    const Color greenColor(255, 0, 0, 200);
    renderer_.renderBox(m_position.x, m_position.y, greenColor);
}

void Fruit::update()
{
}

int Fruit::getX()
{
    return m_position.x;
}

int Fruit::getY()
{
    return m_position.y;
}

Point2D Fruit::getPosition()
{
    return m_position;
}

void Fruit::generateNewPosition()
{
    generateRandomPosition();
}

void Fruit::generateRandomPosition()
{
    m_position.x = rand() % (Constants::GAME_FIELD_WIDTH - 2) + 2;
    m_position.y = rand() % (Constants::GAME_FIELD_HEIGHT - 2) + 2;
}
