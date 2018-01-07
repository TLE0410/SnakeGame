#ifndef CONSTANTS_H
#define CONSTANTS_H

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

    static const int SNAKE_MOVE_RATE = 300; // in millisecods

    static const int SNAKE_INITIAL_LENGTH = 3;
    static const int SNAKE_BODY_WIDTH = 15;
    static const int SNAKE_HEAD_WIDTH = 19;
    static const int APPLE_RADIUS = 10;

    static const char *GAME_WINDOW_TITLE = "Snake Game";
}

#endif



