#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Renderer.h"

class GameObject
{
public:
    GameObject(Renderer &renderer);
    virtual ~GameObject() = default;
    virtual void render() = 0;
    virtual void update() = 0;
protected:
    Renderer &renderer_;
private:
    GameObject() = default;
};

inline GameObject::GameObject(Renderer &renderer) : renderer_(renderer)
{
}

#endif
