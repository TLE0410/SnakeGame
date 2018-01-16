#ifndef TEXTTEXTURE_H
#define TEXTTEXTURE_H

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

class TextTexture
{
public:
    TextTexture(SDL_Renderer &renderer, int x, int y, const std::string& text, const int fontSize);
    TextTexture() = delete;
    ~TextTexture();
    void updateTextTexture(const std::string& text);
    void updateText(const std::string& text);
    const SDL_Rect* getTextRect() const;
    SDL_Texture* getTexture() const;
private:
    SDL_Texture* createTextTexture(const char* textToRender) const;

    SDL_Texture *text_texture_ = nullptr;
    SDL_Renderer &sdl_renderer_;
    TTF_Font *font_ = nullptr;
    SDL_Rect text_rect_;
};

#endif // TEXTTEXTURE_H
