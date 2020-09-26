#pragma one
#include "./include/typedef.h"

//Convert Hex to String
char hexToStringOutput[128];
template <typename T>
const char* HexToString(T value)
{
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
char integerToStringOutput[128];
template <typename T>
const char* itoa(T value)
{
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

//Convert float to string
char floatToStringOutput[128];
const char* FloatToString(float val, uint_8 decimalPlaces = 2)
{
    char* intPtr = (char*)(itoa((int)(val)));
    char* flaotPtr = floatToStringOutput;

    if(val < 0)
        val *= -1;

    while(*intPtr != 0)
    {
        *flaotPtr = *intPtr;
        intPtr++;
        flaotPtr++;
    }
    *flaotPtr = '.';
    flaotPtr++;

    float newValue = val - (int)(val);

    for(uint_8 i = 0; i < decimalPlaces; i++)
    {
        newValue *= 10;
        *flaotPtr = (int)(newValue + 48);
        newValue -= (int)(newValue);
        flaotPtr++;
    }

    *flaotPtr = 0;

    return floatToStringOutput;
}