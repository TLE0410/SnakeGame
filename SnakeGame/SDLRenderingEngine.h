#ifndef RENDERING_ENGINE_H
#define RENDERING_ENGINE_H

#include "Renderer.h"
#include "MovableObserver.h"
#include <SDL.h>
#include <vector>
#include <SDL_ttf.h>

class SdlRenderingEngine : public Renderer
{
public:
    SdlRenderingEngine();
    ~SdlRenderingEngine();
    void renderBox(int x, int y, Color color) const override;
    void renderBox(int x, int y, int width, int height, Color color) const override;
    void pollEvents() override;
    void attachMovableObserver(MovableObserver &movableObserver) override;
    void addCloseEventHandler(CloseEventHandler& closeEventHandler) override;
    void clearScreen() override;
    void renderScreen() override;

    void setText(const std::string textToRender) override;
    void renderText() override;

private:
    void executeChangeDirection(Direction direction);
    void InitializeSDL();
    void processKeyCode(SDL_Event e);
    SDL_Window* window_ = nullptr;
    SDL_Surface* screen_surface_ = nullptr;
    SDL_Renderer* sdl_renderer_ = nullptr;
    std::vector<MovableObserver*> movable_observers_;
    CloseEventHandler* close_event_handler_;

    std::string textToRender_;
    SDL_Texture *text_texture_ = nullptr;
    TTF_Font *font_ = nullptr;
    int text_width_;
    int text_height_;
};

#endif
