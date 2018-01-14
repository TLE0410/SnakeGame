#include "SpriteSheetTexture.h"
#include <SDL_image.h>

SpriteSheetTexture::SpriteSheetTexture(SDL_Renderer &renderer, const std::string& path) :
    sdl_renderer_(renderer)
{
    SDL_Surface* loadedSurface = nullptr;
    loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr)
    {
        throw std::runtime_error("Unable to load image " + path + IMG_GetError());
    }

    texture_ = nullptr;
    texture_ = SDL_CreateTextureFromSurface(&sdl_renderer_, loadedSurface);
    if (texture_ == nullptr)
    {
        throw std::runtime_error("Unable to create texture from " + path + SDL_GetError());
    }

    width_ = loadedSurface->w;
    height_ = loadedSurface->h;
    SDL_FreeSurface(loadedSurface);
}

SpriteSheetTexture::~SpriteSheetTexture()
{
    SDL_DestroyTexture(texture_);
    texture_ = nullptr;
}

void SpriteSheetTexture::render(int x, int y, SDL_Rect* clip, const double angle) const
{
    SDL_Rect renderQuad = { x, y, width_, height_ };

    if (clip != nullptr)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    SDL_RenderCopyEx(&sdl_renderer_, texture_, clip, &renderQuad, angle, NULL, SDL_FLIP_NONE);
}
