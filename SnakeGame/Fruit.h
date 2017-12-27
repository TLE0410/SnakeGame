#ifndef FRUIT_H
#define FRUIT_H

#include "GameObject.h"
#include "Point2D.h"

class Fruit : public GameObject
{
public:
    Fruit(int x, int y);
    void render();
    void update();
    void handleInput() {};

    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
private:
    Point2D m_position;
};

#endif
