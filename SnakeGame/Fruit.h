#ifndef FRUIT_H
#define FRUIT_H

#include "GameObject.h"
#include "Point2D.h"

class Fruit : public GameObject
{
public:
    void render();
    void update();
    void handleInput() {};

    int getX();
    int getY();
    Point2D getPosition();
    void generateNewPosition();
private:
    Point2D m_position;
    void generateRandomPosition();
};

#endif
