#include <iostream>
#include "SDLRenderingEngine.h"
#include <SDL.h>
#include "Constants.h"

void SdlRenderingEngine::renderBox(int x, int y, int color) const
{
    //Clear screen

    //Clear screen
    SDL_SetRenderDrawColor(sdl_renderer_, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(sdl_renderer_);

    //Render red filled quad
    int width = Constants::SCREEN_WIDTH;
    int height = Constants::SCREEN_HEIGHT;
    SDL_Rect fillRect = { width / 4, height / 4, width / 2, height / 2 };

    SDL_SetRenderDrawColor(sdl_renderer_, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(sdl_renderer_, &fillRect);

    //Render green outlined quad
    SDL_Rect outlineRect = { width / 6, height / 6, width * 2 / 3, height * 2 / 3 };
    SDL_SetRenderDrawColor(sdl_renderer_, 0x00, 0xFF, 0x00, 0xFF);
    SDL_RenderDrawRect(sdl_renderer_, &outlineRect);

    //Draw blue horizontal line
    SDL_SetRenderDrawColor(sdl_renderer_, 0x00, 0x00, 0xFF, 0xFF);
    SDL_RenderDrawLine(sdl_renderer_, 0, height / 2, width, height / 2);

    //Draw vertical line of yellow dots
    SDL_SetRenderDrawColor(sdl_renderer_, 0xFF, 0xFF, 0x00, 0xFF);
    for (int i = 0; i < height; i += 4)
    {
        SDL_RenderDrawPoint(sdl_renderer_, width / 2, i);
    }

    //Update screen
    SDL_RenderPresent(sdl_renderer_);
}

void SdlRenderingEngine::pollEvents()
{
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0)
    {
        //User requests quit
        if (e.type == SDL_QUIT)
        {
            // handle quit event
            // quit = true;
        }
    }
}

void SdlRenderingEngine::attachMovableObserver(MovableObserver& movableObserver)
{
    movable_observers_.push_back(&movableObserver);
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

SdlRenderingEngine::SdlRenderingEngine()
{
    InitializeSDL();
}

SdlRenderingEngine::~SdlRenderingEngine()
{
    SDL_FreeSurface(screen_surface_);
    screen_surface_ = nullptr;

    SDL_DestroyWindow(window_);
    window_ = nullptr;

    SDL_Quit();
}


