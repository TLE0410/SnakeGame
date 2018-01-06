#ifndef COLOR_H
#define COLOR_H
#include <cstdint>

struct Color
{
    Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) : 
        red(red), green(green), blue(blue), alpha(alpha) {}
    Color() = default;
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
};

#endif // COLOR_H
