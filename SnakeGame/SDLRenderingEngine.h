#ifndef RENDERING_ENGINE_H
#define RENDERING_ENGINE_H

#include "Renderer.h"
#include "MovableObserver.h"
#include <SDL.h>
#include <vector>

class SdlRenderingEngine : public Renderer
{
public:
    SdlRenderingEngine();
    ~SdlRenderingEngine();
    void renderBox(int x, int y, int color) const override;
    void pollEvents() override;
    void attachMovableObserver(MovableObserver &movableObserver) override;
private:
    void InitializeSDL();
    SDL_Window* window_;
    SDL_Surface* screen_surface_;
    SDL_Renderer* sdl_renderer_;
    std::vector<MovableObserver*> movable_observers_;
};

#endif
