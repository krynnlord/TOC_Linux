#include "../headers/header.h"

/*
COLORS LIST
1: Blue
2: Green
3: Cyan
4: Red
5: Purple
6: Yellow (Dark)
7: Default white
8: Gray/Grey
9: Bright blue
10: Bright green
11: Bright cyan
12: Bright red
13: Pink/Magenta
14: Yellow
15: Bright white
*/
void Color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}