#include "../include/omath.h"

//Split byte at the middle (|0101, 0101|)
int SplitByte(int byte, int who)
{
    if(who == 0)
        return byte & 0x0F;
    else
        return byte & 0xF0;
}

double pow(double x, double y)
{
    double result = 0;
    while (y != 0)
    {
        result *= x;
        --y;
    }

    return result;
}