#pragma once

#include "./include/ports/IO.cpp"
#include "./include/kprint.h"
#include "./include/typedef.h"

uint_16 CurrentCursorPosition;

void SetCursorPosition(uint_16 position)
{
    outb(0x3d4, 0x0F);
    outb(0x3d5, (uint_8)(position & 0xFF));
    outb(0x3d4, 0x0e);
    outb(0x3d5, (uint_8)(position >> 8) & 0xFF);

    CurrentCursorPosition = position;
}

uint_16 PositionFromCords(uint_8 x, uint_8 y)
{
    return y * VGA_WIDTH + x;
}

void printf(const char* str)
{
    uint_8* charPtr = (uint_8*)str;
    uint_16 index = CurrentCursorPosition;

    while(*charPtr != 0)
    {
        switch (*charPtr)
        {
        case 10:
            index += VGA_WIDTH;

            break;
        case 13:
            index -= index % VGA_WIDTH;

            break;
        default:
            *(VGA_MEMORY + index * 2) = *charPtr;

            index++;
            break;
        }


        charPtr++;
    }

    SetCursorPosition(index);
}

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