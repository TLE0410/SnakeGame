#include <iostream>
#include "SDLRenderingEngine.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include "Constants.h"
#include "CrossPlatformUtils.h"
#include "Utils.h"

SdlRenderingEngine::SdlRenderingEngine()
{
    InitializeSDL();
}

void SdlRenderingEngine::renderBox(int x, int y, Color color) const
{
    renderBox(x, y, 1, 1, color);
}

void SdlRenderingEngine::renderBox(int x, int y, int width, int height, Color color) const
{
    const int cellWidth = Constants::GAME_FIELD_WIDTH_PIXELS / Constants::GAME_FIELD_WIDTH_CELLS;
    const int cellHeight = Constants::GAME_FIELD_HEIGHT_PIXELS / Constants::GAME_FIELD_HEIGHT_CELLS;

    int boxWidth = cellWidth * width;
    int boxHeight = cellHeight * height;

    const int boxX = (x - 1) * cellWidth;
    const int boxY = (y - 1) * cellHeight;

    SDL_Rect fillRect = { boxX, boxY, boxWidth, boxHeight };

    SDL_SetRenderDrawBlendMode(sdl_renderer_, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(sdl_renderer_, color.red, color.green, color.blue, color.alpha);
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
    SDL_SetRenderDrawColor(sdl_renderer_, 230, 250, 255, 0);
    SDL_RenderClear(sdl_renderer_);
}

void SdlRenderingEngine::renderScreen()
{
    SDL_RenderPresent(sdl_renderer_);
}

void SdlRenderingEngine::setText(const std::string textToRender)
{
    textToRender_ = textToRender;

    const SDL_Color textColor = { 0, 0, 0 };
    SDL_Surface* text_surface = TTF_RenderText_Solid(font_, textToRender.c_str(), textColor);

    if (text_surface == nullptr)
    {
        throw std::runtime_error("Unable to render text surface! SDL_ttf Error: " + std::string(TTF_GetError()));
    }

    text_texture_ = SDL_CreateTextureFromSurface(sdl_renderer_, text_surface);
    if (text_texture_ == nullptr)
    {
        throw std::runtime_error("Unable to create texture from rendered text! SDL Error: " + std::string(SDL_GetError()));
    }

    SDL_FreeSurface(text_surface);

    TTF_SizeText(font_, textToRender_.c_str(), &text_width_, &text_height_);
}

void SdlRenderingEngine::renderText()
{
    SDL_Rect renderQuad = { 0, Constants::GAME_FIELD_HEIGHT_PIXELS,
        text_width_, text_height_};

    SDL_RenderCopy(sdl_renderer_, text_texture_, NULL, &renderQuad);
    //SDL_RenderCopyEx(sdl_renderer_, text_texture_, NULL, &renderQuad, NULL, NULL, SDL_FLIP_NONE);
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
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        throw std::runtime_error(
            "SDL could not initialize! SDL_Error: " + std::string(SDL_GetError()));
    }

    if (TTF_Init() == -1)
    {
        throw std::runtime_error("SDL_ttf could not initialize! SDL_ttf Error: " + std::string(SDL_GetError()));
    }

    window_ = SDL_CreateWindow(Constants::GAME_WINDOW_TITLE, 
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window_ == nullptr)
    {
        throw std::runtime_error("Window could not be created!SDL_Error: " + std::string(SDL_GetError()));
    }

    screen_surface_ = SDL_GetWindowSurface(window_);
    sdl_renderer_ = CrossPlatform::getRenderer(window_);

    if (sdl_renderer_ == nullptr)
    {
        throw std::runtime_error("Renderer could not be created! SDL_Error: " + std::string(SDL_GetError()));
    }

    font_ = TTF_OpenFont("res\\fonts\\arcadeclassic.ttf", 40);
    if (font_ == nullptr)
    {
        throw std::runtime_error("Failed to load the font! SDL_ttf Error: " + std::string(SDL_GetError()));
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
    SDL_DestroyRenderer(sdl_renderer_);
    sdl_renderer_ = nullptr;

    SDL_FreeSurface(screen_surface_);
    screen_surface_ = nullptr;

    SDL_DestroyWindow(window_);
    window_ = nullptr;

    SDL_Quit();
}


