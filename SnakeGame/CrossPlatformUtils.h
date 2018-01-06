#ifndef CROSSPLATFORMUTILS_H
#define CROSSPLATFORMUTILS_H

#include "SDL.h"

namespace CrossPlatform
{
    static SDL_Renderer* getRenderer(SDL_Window* window)
    {
        // for some reason on Windows it has to be CreateRender vs on Mac/Linux we need 
        // to get an existing render
#ifdef _WIN32
        return SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
#else
        return SDL_GetRenderer(window);
#endif
    }
}

#endif // CROSSPLATFORMUTILS_H
