#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
public:
    virtual void render() = 0;
    virtual void update() = 0;
    virtual void handleInput() = 0;
};

#endif
