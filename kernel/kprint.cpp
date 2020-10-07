#pragma once

#include "./include/ports/IO.cpp"
#include "./include/kprint.h"
#include "./include/typedef.h"
#include "./MEM/Memory.cpp"

uint_16 CurrentCursorPosition;

void SetCursorPosition(uint_16 position)
{
    //TODO: Move Scrolldown from printf to here
    //TODO: Add Scrollup function
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

void ClearScreen(uint_64 color = BACKGROUND_BLACK | FOREGROUND_WHYTE)
{
    uint_64 val = 0;
    val += color << 8;
    val += color << 24;
    val += color << 40;
    val += color << 56;

    for(uint_64* i = (uint_64*)VGA_MEMORY; i < (uint_64*)(VGA_MEMORY + 4000); i++)
        *i = val;

    SetCursorPosition(0);
}

void PrintChar(char ch, uint_8 color = BACKGROUND_BLACK | FOREGROUND_WHYTE)
{
    *(VGA_MEMORY + CurrentCursorPosition * 2) = ch;
    *(VGA_MEMORY + CurrentCursorPosition * 2 + 1) = color;

    SetCursorPosition(CurrentCursorPosition + 1);
}

void FillLine(uint_8 y, uint_8 color = BACKGROUND_BLACK | FOREGROUND_WHYTE)
{
    uint_16 prevCursorPosition = CurrentCursorPosition;

    SetCursorPosition(PositionFromCords(0, y));

    for(int i = 0; i < VGA_WIDTH; i++)
    {
        PrintChar(0, color);
        SetCursorPosition(PositionFromCords(i, y));
    }

    SetCursorPosition(prevCursorPosition);
}

void printf(string str, uint_8 color = BACKGROUND_BLACK | FOREGROUND_WHYTE)
{
    uint_8* charPtr = (uint_8*)str;
    uint_16 index = CurrentCursorPosition;

    while(*charPtr != 0)
    {
        switch (*charPtr)
        {
        case 10:
            if (CurrentCursorPosition >= PositionFromCords(0, VGA_HEIGHT - 1))
            {
                memmove(VGA_MEMORY, VGA_MEMORY + 80*2, 80*25*2);

                FillLine(VGA_HEIGHT - 1);
                index = PositionFromCords(0, VGA_HEIGHT - 1);
            } else
                index += VGA_WIDTH;

            break;
        case 13:
            index -= index % VGA_WIDTH;

            break;
        default:
            *(VGA_MEMORY + index * 2) = *charPtr;
            *(VGA_MEMORY + index * 2 + 1) = color;
            index++;
            break;
        }

        charPtr++;
    }

    SetCursorPosition(index);
}