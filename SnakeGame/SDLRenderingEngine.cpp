#include <iostream>
#include "SDLRenderingEngine.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include "Constants.h"
#include "CrossPlatformUtils.h"
#include "Utils.h"
#include "SpritePositions.h"
#include <SDL_image.h>

SdlRenderingEngine::SdlRenderingEngine()
{
    InitializeSDL();
}

void SdlRenderingEngine::renderBox(Point2D point, Color color) const
{
    renderBox(point.x, point.y, 1, 1, color);
}

void SdlRenderingEngine::renderBox(int x, int y, int width, int height, Color color) const
{
    const int cellWidth = Constants::GAME_FIELD_WIDTH_PIXELS / Constants::GAME_FIELD_WIDTH_CELLS;
    const int cellHeight = Constants::GAME_FIELD_HEIGHT_PIXELS / Constants::GAME_FIELD_HEIGHT_CELLS;

    const int boxWidth = cellWidth * width;
    const int boxHeight = cellHeight * height;

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
        if (e.type == SDL_QUIT)
        {
            userInputEventHanlder_->handleCloseEvent();
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

void SdlRenderingEngine::addUserInputEventHanlder(UserInputEventHandler& closeEventHandler)
{
    userInputEventHanlder_ = &closeEventHandler;
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
    scrore_text_->updateText(textToRender);
}

void SdlRenderingEngine::renderText()
{
    SDL_RenderCopy(sdl_renderer_, scrore_text_->getTexture(),
        nullptr, scrore_text_->getTextRect());
}

void SdlRenderingEngine::renderGameLost() const
{
    renderGameOverBox();
    renderGameOverText(*game_lost_text_large_, *game_lost_text_small_);
}

void SdlRenderingEngine::renderGameWon() const
{
    renderGameOverBox();
    renderGameOverText(*game_won_text_large_, *game_won_text_small_);
}

void SdlRenderingEngine::renderSnakeBox(DirectionalPoint2D point, SnakeBodyPart bodyPart) const
{
    int x = (point.x - 1) * Constants::GAME_CELL_WIDTH_PIXELS;
    int y = (point.y - 1) * Constants::GAME_CELL_HEIGHT_PIXELS;

    double textureRotationAngle = getAngleFromBoxDirection(point.direction);

    switch (bodyPart)
    {
        case Head:
        {
            snake_texture_->render(x, y, &SpritePositions::SNAKE_HEAD, textureRotationAngle);
            break;
        }
        case Tail:
        {
            const double textureRotationAngle = getAngleFromDirection(point.direction.next);
            snake_texture_->render(x, y, &SpritePositions::SNAKE_TAIL, textureRotationAngle);
            break;
        }
        case Body:
        {
            if (point.direction.next == point.direction.prev)
            {
                textureRotationAngle = getAngleFromDirection(point.direction.next);
                snake_texture_->render(x, y, &SpritePositions::SNAKE_BODY_STRAIGHT, textureRotationAngle);
            }
            else
            {
                snake_texture_->render(x, y, &SpritePositions::SNAKE_BODY_TURN, textureRotationAngle);
            }
        }
    }
}

void SdlRenderingEngine::renderFruitBox(Point2D point) const
{
    int x = (point.x - 1) * Constants::GAME_CELL_WIDTH_PIXELS;
    int y = (point.y - 1) * Constants::GAME_CELL_HEIGHT_PIXELS;

    fruit_texture_->render(x, y, &SpritePositions::APPLE, 0);
}

double SdlRenderingEngine::getAngleFromBoxDirection(const BoxDirection& direction) const
{
    if (direction.next == up && direction.prev == up)  
        return Constants::UP_ANGLE;

    if (direction.next == down && direction.prev == down)       
        return Constants::DOWN_ANGLE;
    
    if (direction.next == left && direction.prev == left)
        return Constants::LEFT_ANGLE;

    if (direction.next == right && direction.prev == right)
        return Constants::RIGHT_ANGLE;

    if (direction.next == up && direction.prev == left)
        return 0;

    if (direction.next == up && direction.prev == right)
        return 270.0;

    if (direction.next == down && direction.prev == left)
        return 90.0;

    if (direction.next == down && direction.prev == right)
        return 180.0;

    if (direction.next == left && direction.prev == up)
        return 180.0;

    if (direction.next == left && direction.prev == down)
        return 270.0;

    if (direction.next == right && direction.prev == up)
        return 90.0;

    if (direction.next == right && direction.prev == down)
        return 0.0;

    return 0;
}

double SdlRenderingEngine::getAngleFromDirection(const Direction& direction) const
{
    if (direction == up)
        return 270;
    if (direction == down)
        return 90;
    if (direction == left)
        return 180;
    if (direction == right)
        return 0;
    return 0;
}

void SdlRenderingEngine::renderGameOverBox() const
{
    using namespace Constants;
    SDL_Rect fillRect = { 
        GAME_OVER_BOX_X, GAME_OVER_BOX_Y, 
        GAME_OVER_BOX_WIDTH, GAME_OVER_BOX_HEIGHT};

    const Color color(0, 153, 153, 255);

    SDL_SetRenderDrawBlendMode(sdl_renderer_, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(sdl_renderer_, color.red, color.green, color.blue, color.alpha);
    SDL_RenderFillRect(sdl_renderer_, &fillRect);
}

void SdlRenderingEngine::renderGameOverText(const TextTexture& large_text, const TextTexture& small_text) const
{
    SDL_RenderCopy(sdl_renderer_, large_text.getTexture(),
        nullptr, large_text.getTextRect());

    SDL_RenderCopy(sdl_renderer_, small_text.getTexture(),
        nullptr, small_text.getTextRect());
}

void SdlRenderingEngine::executeChangeDirection(Direction direction)
{
    for (MovableObserver* observer : movable_observers_)
    {
        observer->changeDirection(direction);
    }
}

void SdlRenderingEngine::initializeGameOverText()
{
    game_lost_text_large_ = std::make_shared<TextTexture>(
        *sdl_renderer_,  Constants::GAME_OVER_MESSAGE_X, Constants::GAME_OVER_MESSAGE_Y, 
        "Game Over", Constants::MAIN_FONT_SIZE);

    game_lost_text_small_ = std::make_shared<TextTexture>(
        *sdl_renderer_, Constants::PRESS_ENTER_MESSAGE_X, Constants::PRESS_ENTER_MESSAGE_Y,
        "press Enter and try harder", Constants::SMALLER_FONT_SIZE);

    game_won_text_large_ = std::make_shared<TextTexture>(
        *sdl_renderer_, Constants::GAME_OVER_MESSAGE_X, Constants::GAME_OVER_MESSAGE_Y,
        "You won!", Constants::MAIN_FONT_SIZE);

    game_won_text_small_ = std::make_shared<TextTexture>(
        *sdl_renderer_, Constants::PRESS_ENTER_MESSAGE_X, Constants::PRESS_ENTER_MESSAGE_Y,
        "Press Enter and do it again", Constants::SMALLER_FONT_SIZE);
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

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        throw std::runtime_error("SDL_image could not initialize! SDL_image Error: " + std::string(IMG_GetError()));
    }

    screen_surface_ = SDL_GetWindowSurface(window_);
    sdl_renderer_ = CrossPlatform::getRenderer(window_);

    if (sdl_renderer_ == nullptr)
    {
        throw std::runtime_error("Renderer could not be created! SDL_Error: " + std::string(SDL_GetError()));
    }

    scrore_text_ = std::make_shared<TextTexture>(
        *sdl_renderer_, 0, Constants::GAME_FIELD_HEIGHT_PIXELS, "Score 0", 
        Constants::MAIN_FONT_SIZE);

    initializeGameOverText();

    snake_texture_ = std::make_shared<SpriteSheetTexture>(*sdl_renderer_, Constants::SNAKE_IMAGE_PATH);
    fruit_texture_ = std::make_shared<SpriteSheetTexture>(*sdl_renderer_, Constants::SNAKE_IMAGE_PATH);
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
        case SDLK_RETURN:
            userInputEventHanlder_->handleNewGameEvent();
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

