#include <iostream>
#include "SDLRenderingEngine.h"
#include <SDL.h>
#include "Constants.h"

SdlRenderingEngine::SdlRenderingEngine()
{
    InitializeSDL();
}

void SdlRenderingEngine::renderBox(int x, int y, int color) const
{
    int boxWidth = Constants::SCREEN_WIDTH / Constants::GAME_FIELD_WIDTH;
    int boxHeight = Constants::SCREEN_HEIGHT / Constants::GAME_FIELD_HEIGHT;

    int boxX = (x - 1) * boxWidth;
    int boxY = (y - 1) * boxHeight;

    SDL_Rect fillRect = { boxX, boxY, boxWidth, boxHeight };

    SDL_SetRenderDrawColor(sdl_renderer_, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(sdl_renderer_, &fillRect);
}

void SdlRenderingEngine::pollEvents()
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0)
    {
        //User requests quit
        if (e.type == SDL_QUIT)
        {
            close_event_handler_->handleCloseEvent();
        }
        else if (e.type == SDL_KEYDOWN)
        {
            processKeyCode(e);
        }
    }
}

void SdlRenderingEngine::attachMovableObserver(MovableObserver& movableObserver)
{
    movable_observers_.push_back(&movableObserver);
}

void SdlRenderingEngine::addCloseEventHandler(CloseEventHandler& closeEventHandler)
{
    close_event_handler_ = &closeEventHandler;
}

void SdlRenderingEngine::clearScreen()
{
    SDL_SetRenderDrawColor(sdl_renderer_, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(sdl_renderer_);
}

void SdlRenderingEngine::renderScreen()
{
    SDL_RenderPresent(sdl_renderer_);
}

void SdlRenderingEngine::executeChangeDirection(Direction direction)
{
    for (MovableObserver* observer : movable_observers_)
    {
        observer->changeDirection(direction);
    }
}

void SdlRenderingEngine::InitializeSDL()
{
    window_ = nullptr;
    screen_surface_ = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        throw std::runtime_error(
            "SDL could not initialize! SDL_Error: " + std::string(SDL_GetError()));
    }
    window_ = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window_ == nullptr)
    {
        throw std::runtime_error(
            "Window could not be created!SDL_Error: " + std::string(SDL_GetError()));
    }

    screen_surface_ = SDL_GetWindowSurface(window_);
    sdl_renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);

    if (sdl_renderer_ == nullptr)
    {
        throw std::runtime_error(
            "Renderer could not be created! SDL_Error: " + std::string(SDL_GetError()));

    }
}

void SdlRenderingEngine::processKeyCode(SDL_Event e)
{
    switch (e.key.keysym.sym)
    {
        case SDLK_UP:
            executeChangeDirection(up);
            break;
        case SDLK_DOWN:
            executeChangeDirection(down);
            break;
        case SDLK_LEFT:
            executeChangeDirection(left);
            break;
        case SDLK_RIGHT:
            executeChangeDirection(right);
            break;
    }
}

SdlRenderingEngine::~SdlRenderingEngine()
{
    SDL_FreeSurface(screen_surface_);
    screen_surface_ = nullptr;

    SDL_DestroyWindow(window_);
    window_ = nullptr;

    SDL_Quit();
}


