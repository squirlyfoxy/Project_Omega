#pragma one

#ifndef _STRING_H
#define _STRING_H

#include "./typedef.h"

#include <omath.h>

uint_32 strlen(string str);

int atoi(string str);

//Convert Hex to String
template <typename T>
const char* HexToString(T value)
{
    extern char hexToStringOutput[128];

    T* valPtr = &value;
    uint_8* ptr;
    uint_8 tmp, size = (sizeof(T)) * 2 - 1, i;

    for (i = 0; i < size; i++)
    {
        ptr = ((uint_8*)valPtr + i);
        tmp = ((*ptr & 0xF0) >> 4);
        hexToStringOutput[size - (i * 2 + 1)] = tmp + (tmp > 9 ? 55 : 48);
        tmp = ((*ptr & 0x0F));
        hexToStringOutput[size - (i * 2)] = tmp + (tmp > 9 ? 55 : 48);
    }
    hexToStringOutput[size + 1] = 0;

    return hexToStringOutput;
}

//Convert Int to String
template <typename T>
const char* itoa(T value)
{
    extern char integerToStringOutput[128];

    uint_8 isNegative = 0;
    if(value < 0)
    {
        isNegative = 1;
        value *= -1;
        integerToStringOutput[0] = '-';
    }

    uint_8 size = 0;
    uint_64 sizeTester = (uint_64)(value);

    while (sizeTester / 10 > 0)
    {
        sizeTester /= 10;
        size++;
    }

    uint_8 index = 0;
    uint_64 newValue = (uint_64)(value);

    while(newValue / 10 > 0)
    {
        uint_8 remainder = newValue % 10;
        newValue /= 10;

        integerToStringOutput[isNegative + size - index] = remainder + 48;

        index++;
    }

    uint_8 nRemainder = newValue % 10;
    integerToStringOutput[isNegative + size - index] = nRemainder + 48;
    integerToStringOutput[isNegative + size + 1] = 0;

    return integerToStringOutput;
}


const char* FloatToString(float val, uint_8 decimalPlaces);

#endif