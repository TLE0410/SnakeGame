#ifndef CROSSPLATFORMUTILS_H
#define CROSSPLATFORMUTILS_H

#ifdef __APPLE__
    #include <mach-o/dyld.h>
#endif

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

#ifdef __APPLE__
static void printPath()
{
    char path[1024];
    uint32_t size = sizeof(path);
    if (_NSGetExecutablePath(path, &size) == 0)
        printf("executable path is %s\n", path);
    else
        printf("buffer too small; need size %u\n", size);
}
#endif // __APPLE__

#endif // CROSSPLATFORMUTILS_H
