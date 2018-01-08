#include "TextTexture.h"
#include <SDL_ttf.h>

TextTexture::TextTexture(SDL_Renderer &renderer,  int x, int y, const std::string& text) :
    sdl_renderer_(renderer)
{
    text_rect_.x = x;
    text_rect_.y = y;
    font_ = TTF_OpenFont("res\\fonts\\arcadeclassic.ttf", 40);
    updateTextTexture(text);
}

TextTexture::~TextTexture()
{
    SDL_DestroyTexture(text_texture_);
    text_texture_ = nullptr;

    TTF_CloseFont(font_);
    font_ = nullptr;
}

void TextTexture::updateTextTexture(const std::string& text)
{
    if (text_texture_ != nullptr)
    {
        SDL_DestroyTexture(text_texture_);
        text_texture_ = nullptr;
    }

    text_texture_ = createTextTexture(text.c_str());
    TTF_SizeText(font_, text.c_str(), &text_rect_.w, &text_rect_.h);
}

void TextTexture::updateText(const std::string& text)
{
    updateTextTexture(text);
}

SDL_Rect* TextTexture::getTextRect()
{
    return &text_rect_;
}

SDL_Texture* TextTexture::getTexture() const
{
    return text_texture_;
}

SDL_Texture* TextTexture::createTextTexture(const char* textToRender) const
{
    const SDL_Color blackColor = { 0, 0, 0 };
    SDL_Surface* text_surface = TTF_RenderText_Solid(font_, textToRender, blackColor);

    if (text_surface == nullptr)
    {
        throw std::runtime_error("Unable to render text surface! SDL_ttf Error: " + std::string(TTF_GetError()));
    }

    SDL_Texture* result = SDL_CreateTextureFromSurface(&sdl_renderer_, text_surface);
    if (result == nullptr)
    {
        throw std::runtime_error("Unable to create texture from rendered text! SDL Error: " + std::string(SDL_GetError()));
    }

    SDL_FreeSurface(text_surface);

    return result;
}
