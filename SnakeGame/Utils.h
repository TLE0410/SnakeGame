#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "Constants.h"

namespace Utils
{
    void static PrintText(int x, int y, std::string text)
    {
        printf("\033[%d;%dH%s", y + 2, x + 5, text.c_str());
    }

    void static Log(std::string messageToLog)
    {
        PrintText(5, Constants::GAME_FIELD_WIDTH + 2, messageToLog.c_str());
    }
}

#endif
