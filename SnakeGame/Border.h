#ifndef BORDER_H
#define BORDER_H

#include <vector>
#include "GameObject.h"
#include "Point2D.h"

class Border : public GameObject
{
public:
    Border();
    void render();
    void update() {};
    void handleInput() {};

private:
    std::vector<Point2D*> m_borderPoints;

    void addTopHorizontalLine();
    void addLeftVerticalLine();
    void addRightVerticalLine();
    void addBottomHorizontalLine();
};


#endif