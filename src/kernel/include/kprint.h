#ifndef _KPRINT_H
#define _KPRINT_H

#define VGA_MEMORY (unsigned char*) 0xb8000

#define VGA_WIDTH 80
#define VGA_HEIGHT 25

#include "typedef.h"

void SetCursorPosition(uint_16 position);
uint_16 PositionFromCords(uint_8 x, uint_8 y);
void ClearScreen(uint_64 color);
void PrintChar(char ch, uint_8 color);
void FillLine(uint_8 y, uint_8 color);
void printf(string str, uint_8 color);


//VGA Colors
//Foreground
enum ForegroundColors
{
    FOREGROUND_BLACK = 0x00,
    FOREGROUND_GREEN = 0x02,
    FOREGROUND_CYAN  = 0x03,
    FOREGROUND_MAGENTA = 0x05,
    FOREGROUND_BROWN = 0x06,
    FOREGROUND_LIGHTGRAY = 0x07,
    FOREGROUND_DARKGRAY = 0x08,
    FOREGROUND_LIGHTBLUE = 0x09,
    FOREGROUND_LIGHTGREEN = 0x0A,
    FOREGROUND_LIGHTCYAN = 0x0B,
    FOREGROUND_LIGHTRED = 0x0C,
    FOREGROUND_LIGHTMAGENTA = 0x0D,
    FOREGROUND_YELLOW = 0x0E,
    FOREGROUND_WHYTE = 0x0F
};

//Background
enum BackgroundColors
{
    BACKGROUND_BLACK = 0x00,
    BACKGROUND_BLUE = 0x10,
    BACKGROUND_GREEN = 0x20,
    BACKGROUND_CYAN = 0x30,
    BACKGROUND_RED = 0x40,
    BACKGROUND_MAGENTA = 0x50,
    BACKGROUND_BROWN = 0x60,
    BACKGROUND_LIGHTGRAY = 0x70,
    BACKGROUND_BLICKINBLACK = 0x80,
    BACKGROUND_BLICKINBLUE = 0x90,
    BACKGROUND_BLICKINGREEN = 0xA0,
    BACKGROUND_BLICKINCYAN = 0xB0,
    BACKGROUND_BLICKINRED = 0xC0,
    BACKGROUND_BLICKINMAGENTA = 0xD0,
    BACKGROUND_BLICKINYELLOW = 0xE0,
    BACKGROUND_BLICKINWHYTE = 0xF0
};

#endif