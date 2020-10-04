#pragma once

#include "../include/memory.h"

void memcpy(void* destination, void* source, uint_64 num)
{
    if(num <= 8) //8 bytes
    {
        uint_8* valPtr = (uint_8*)(source);

        for (uint_8* ptr = (uint_8*)(destination); ptr < (uint_8*)((uint_64)(destination + num)); ptr++)
        {
            *ptr = *valPtr;
            valPtr++;
        }
    } else
    {
        uint_64 proceedingByte = num % 8; //How many bytes?
        uint_64 newNum = num - proceedingByte;
        uint_64* srcPtr = (uint_64*)(source);

        for (uint_64* destPtr = (uint_64*)(destination); destPtr < (uint_64*)((uint_64)(destination + newNum)); destPtr++)
        {
            *destPtr = *srcPtr;
            srcPtr++;
        }

        uint_8* srcPtr8 = (uint_8*)((uint_64)(source + newNum));

        for(uint_8* destPtr8 = (uint_8*)((uint_64)(destination + newNum)); destPtr8 < (uint_8*)((uint_64)(destination + num)); destPtr8++)
        {
            *destPtr8 = *srcPtr8;
            srcPtr8++;
        }
    }
}

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