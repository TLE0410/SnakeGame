#ifndef RENDERING_ENGINE_H
#define RENDERING_ENGINE_H

#include "Renderer.h"
#include "MovableObserver.h"
#include <SDL.h>
#include <vector>
#include "TextTexture.h"
#include <memory>
#include "Point2D.h"
#include "SpriteSheetTexture.h"

class SdlRenderingEngine : public Renderer
{
public:
    SdlRenderingEngine();
    ~SdlRenderingEngine();
    void renderBox(Point2D point, Color color) const override;
    void renderBox(int x, int y, int width, int height, Color color) const override;
    
    void pollEvents() override;
    void attachMovableObserver(MovableObserver &movableObserver) override;
    void addUserInputEventHanlder(UserInputEventHandler& closeEventHandler) override;
    void clearScreen() override;
    void renderScreen() override;
    void setText(const std::string textToRender) override;
    void renderText() override;
    void renderGameLost() const override;
    void renderGameWon() const override;

    double getAngleFromBoxDirection(const BoxDirection& direction) const;
    double getAngleFromDirection(const Direction& direction) const;
    void renderSnakeBox(DirectionalPoint2D point, SnakeBodyPart bodyPart) const override;
    void renderFruitBox(Point2D point) const override;

private:
    void executeChangeDirection(Direction direction);
    void InitializeSDL();
    void processKeyCode(SDL_Event e);
    void renderGameOverBox() const;
    void renderGameOverText() const;

    std::shared_ptr<TextTexture> scrore_text_;
    std::shared_ptr<TextTexture> game_over_text_;
    std::shared_ptr<TextTexture> new_game_text_;

    SDL_Window* window_ = nullptr;
    SDL_Surface* screen_surface_ = nullptr;
    SDL_Renderer* sdl_renderer_ = nullptr;
    std::vector<MovableObserver*> movable_observers_;
    UserInputEventHandler* userInputEventHanlder_{};
    std::shared_ptr<SpriteSheetTexture> snake_texture_;
    std::shared_ptr<SpriteSheetTexture> fruit_texture_;
};

#endif
