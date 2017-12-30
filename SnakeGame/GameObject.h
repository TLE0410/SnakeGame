#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Renderer.h"

class GameObject
{
public:
    GameObject(const Renderer &renderer);
    virtual ~GameObject() = default;
    virtual void render() = 0;
    virtual void update() = 0;
protected:
    const Renderer *renderer_;
private:
    GameObject() = default;
};

inline GameObject::GameObject(const Renderer &renderer) : renderer_(&renderer)
{
}

#endif
