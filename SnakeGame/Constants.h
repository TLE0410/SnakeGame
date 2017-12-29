#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace Constants
{
    static const int GAME_FIELD_WIDTH = 20;
    static const int GAME_FIELD_HEIGHT = 20;

    // millisends
    static const int REFRESH_RATE = 100;
    static const int SNAKE_MOVE_RATE = 300;

    static std::string gameOverMessage =
        " ++ + ++ + ++++++\n\
+ +++++++\n\
+++  ++++ + +++++ +\n\
+++++++\
++ + ++++++++\
\
++ + ++++++  ++ +\
+++++++\
++++++ + ++\
+ ++++++\
++ + +++++ + +";

}

#endif



