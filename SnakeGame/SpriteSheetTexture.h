#ifndef SPRITESHEETTEXTURE_H
#define SPRITESHEETTEXTURE_H

#include <SDL.h>
#include <string>

class SpriteSheetTexture
{
public:
    SpriteSheetTexture(SDL_Renderer &renderer, const std::string& path);
    ~SpriteSheetTexture();
    void render(int x, int y, SDL_Rect* clip, const double angle) const;
private:
    static SDL_Rect& alignSDLRectIfRoted(SDL_Rect& rend_quad, const double& angle);
    int width_;
    int height_;
    SDL_Texture *texture_;
    SDL_Renderer &sdl_renderer_;
};

#endif // SPRITESHEETTEXTURE_H
