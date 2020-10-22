#include "../include/omath.h"

//Split byte at the middle (|0101, 0101|)
int SplitByte(int byte, int who)
{
    if(who == 0)
        return byte & 0x0000FF00;
    else
        return byte & 0x000000FF;
}