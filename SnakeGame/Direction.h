#ifndef DIRECTION_H
#define DIRECTION_H

enum Direction
{
    none, up, down, left, right,
    up_left, up_right, down_left, down_right,
    left_up, left_down, right_up, right_down
};

// directions up, down, left, rigth are straightforward, they idicate the hard/tail/body position

// combined direction like up_left, right_up, etc indicate a snake body 'bend' in 90 degrees 

// up_left means the previous snake body piece is poiting up and then next piece is pointing right
//  
//     snake (H)ead ->  Hbbbbbb <- "up_left" (b)ody
//                            b
//                            b
//         "left_up" (b)ody ->bbbbt <- snake (t)ail

#endif
