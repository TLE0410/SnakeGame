#ifndef BORDER_H
#define BORDER_H

#include <vector>
#include "GameObject.h"
#include "Point2D.h"

class Border : public GameObject
{
public:
    Border(const Renderer &renderer);
    void render() override;
    void update() override{};

    const std::vector<Point2D*> getBorder() const;

private:
    std::vector<Point2D*> m_borderPoints;

    void addTopHorizontalLine();
    void addLeftVerticalLine();
    void addRightVerticalLine();
    void addBottomHorizontalLine();

    Color color;
};


#endif