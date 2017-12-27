#include <stdio.h>
#include "Fruit.h"
#include "Utils.h"

Fruit::Fruit(int x, int y)
{
    m_position.x = x;
    m_position.y = y;
}

void Fruit::render()
{
    Utils::PrintText(m_position.x, m_position.y, "F");
}

void Fruit::update()
{
}

int Fruit::getX()
{
    return m_position.x;
}

void Fruit::setX(int x)
{
    m_position.x = x;
}

int Fruit::getY()
{
    return m_position.y;
}

void Fruit::setY(int y)
{
    m_position.y = y;
}
