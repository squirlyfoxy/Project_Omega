#pragma once

#include "../include/memory.h"

void memset(void* start, uint_64 value, uint_64 num)
{
    if(num <= 8) //8 bytes
    {
        uint_8* valPtr = (uint_8*)(&value);

        for (uint_8* ptr = (uint_8*)(start); ptr < (uint_8*)((uint_64)(start + num)); ptr++)
        {
            *ptr = *valPtr;
            valPtr++;
        }
    } else
    {
        uint_64 proceedingByte = num % 8; //How many bytes?
        uint_64 newNum = num - proceedingByte;

        for (uint_64* ptr = (uint_64*)(start); ptr < (uint_64*)((uint_64)(start + newNum)); ptr++)
        {
            *ptr = value;
        }

        uint_8* valPtr = (uint_8*)&value;

        for(uint_8* ptr = (uint_8*)((uint_64)(start + newNum)); ptr < (uint_8*)((uint_64)(start + num)); ptr++)
        {
            *ptr = *valPtr;
            valPtr++;
        }
    }
}