#ifndef SPRITEPOSITIONS_H
#define SPRITEPOSITIONS_H
#include <SDL.h>

namespace SpritePositions
{
    static SDL_Rect SNAKE_TAIL =             { 0, 0, 40, 40 };
    static SDL_Rect SNAKE_BODY_STRAIGHT =    { 40, 0, 40, 40 };
    static SDL_Rect SNAKE_HEAD =             { 80, 0, 40, 40};
    static SDL_Rect SNAKE_BODY_TURN =        { 0, 40, 40, 40 };
    static SDL_Rect APPLE =                  { 40, 40, 40, 40 };
}
#endif // SPRITEPOSITIONS_H
