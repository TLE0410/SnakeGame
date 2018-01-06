#ifndef FRUIT_H
#define FRUIT_H

#include "GameObject.h"
#include "Point2D.h"

class Fruit : public GameObject
{
public:
    Fruit(const Renderer &renderingEngine);
    void render() override;
    void update() override;

    int getX();
    int getY();
    Point2D getPosition();
    void generateNewPosition();
private:
    Point2D m_position;
    void generateRandomPosition();
};

#endif
