#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace Constants
{
    // screen parameters
    static const int SCREEN_WIDTH = 400;
    static const int SCREEN_HEIGHT = 440;

    static const int GAME_FIELD_WIDTH_CELLS = 10;
    static const int GAME_FIELD_HEIGHT_CELLS = 10;

    static const int GAME_FIELD_WIDTH_PIXELS = SCREEN_WIDTH;
    static const int GAME_FIELD_HEIGHT_PIXELS = 400;

    static const int SCORE_BOARD_WIDTH_PIXELS = SCREEN_WIDTH;
    static const int SCORE_BOARD_HEIGHT_PIXELS = SCREEN_HEIGHT - GAME_FIELD_HEIGHT_PIXELS;

    static const int GAME_OVER_BOX_X = 50;
    static const int GAME_OVER_BOX_Y = 150;
    static const int GAME_OVER_BOX_WIDTH = 300;
    static const int GAME_OVER_BOX_HEIGHT = 100;
    static const int GAME_OVER_MESSAGE_X = 50;
    static const int GAME_OVER_MESSAGE_Y = 150;

    static const int SNAKE_MOVE_RATE = 300; // in millisecods

    static const int SNAKE_INITIAL_LENGTH = 3;
    static const int SNAKE_BODY_WIDTH = 15;
    static const int SNAKE_HEAD_WIDTH = 19;
    static const int APPLE_RADIUS = 10;

    static const char *GAME_WINDOW_TITLE = "Snake Game";

    static const double RIGHT_ANGLE = 0;
    static const double DOWN_ANGLE = 90;
    static const double LEFT_ANGLE = 180;
    static const double UP_ANGLE = 270;
    
    static const std::string SNAKE_IMAGE_PATH = "res/images/Snake.png";
    static const char *FONT_PATH = "res/fonts/arcadeclassic.ttf";
}

#endif
