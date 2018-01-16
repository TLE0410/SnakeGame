#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace Constants
{
    // screen parameters
    static const int GAME_FIELD_WIDTH_CELLS = 10;
    static const int GAME_FIELD_HEIGHT_CELLS = 10;

    static const int GAME_CELL_WIDTH_PIXELS = 40;
    static const int GAME_CELL_HEIGHT_PIXELS = 40;

    // 400 by 400 pixels
    static const int SCREEN_WIDTH = GAME_FIELD_WIDTH_CELLS * GAME_CELL_WIDTH_PIXELS;
    static const int SCORE_BOARD_WIDTH_PIXELS = SCREEN_WIDTH;

    static const int SCORE_BOARD_HEIGHT_PIXELS = 40;
    static const int SCREEN_HEIGHT = GAME_FIELD_HEIGHT_CELLS * GAME_CELL_HEIGHT_PIXELS + SCORE_BOARD_HEIGHT_PIXELS;

    static const int GAME_FIELD_WIDTH_PIXELS = SCREEN_WIDTH;
    static const int GAME_FIELD_HEIGHT_PIXELS = SCREEN_WIDTH;
    
    static const int GAME_OVER_BOX_X = 50;
    static const int GAME_OVER_BOX_Y = 150;
    static const int GAME_OVER_BOX_WIDTH = 300;
    static const int GAME_OVER_BOX_HEIGHT = 100;
    static const int GAME_OVER_MESSAGE_X = 105;
    static const int GAME_OVER_MESSAGE_Y = 160;
    static const int PRESS_ENTER_MESSAGE_X = 65;
    static const int PRESS_ENTER_MESSAGE_Y = 205;

    static const int SNAKE_MOVE_RATE = 300; // in millisecods

    static const int SNAKE_INITIAL_LENGTH = 3;
    static const int MAX_SCORE = GAME_FIELD_HEIGHT_CELLS * GAME_FIELD_WIDTH_CELLS - SNAKE_INITIAL_LENGTH;
    static const int SNAKE_START_POSITION_X = 3;
    static const int SNAKE_START_POSITION_Y = 1;

    static const char *GAME_WINDOW_TITLE = "Snake";

    static const double RIGHT_ANGLE = 0;
    static const double DOWN_ANGLE = 90;
    static const double LEFT_ANGLE = 180;
    static const double UP_ANGLE = 270;
    
    static const std::string SNAKE_IMAGE_PATH = "res/images/Snake.png";
    static const char *FONT_PATH = "res/fonts/arcadeclassic.ttf";

    static const int MAIN_FONT_SIZE = 40;
    static const int SMALLER_FONT_SIZE = 22;
}

#endif
