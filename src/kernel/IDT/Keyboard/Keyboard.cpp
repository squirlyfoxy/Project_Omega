#pragma once

#include "../../include/ports/Keyboard/keyboard.h"

bool leftShiftPressed = false;
bool rightShiftPressed = false;
uint_8 lastScanCode;

void StandardKeyboardHandler(uint_8 scanCode, uint_8 chr)
{
    if(chr != 0)
    {
        switch (leftShiftPressed | rightShiftPressed)
        {
            case true:
                PrintChar(chr - 32);
                break;
            case false:
                PrintChar(chr);
                break;
            
        }
    }
    else
    {
        switch (scanCode)
        {
            case 0x8e: //Backspace
            SetCursorPosition(GetCurrentCursorPosition() - 1);
            PrintChar(' ');
            SetCursorPosition(GetCurrentCursorPosition() - 1);
                break;
            case 0x2a: //Left shift
            leftShiftPressed = true;
                break;
            case 0xaa: //Left shift released
            leftShiftPressed = false;
                break;
            case 0x36: //Right shift
            rightShiftPressed = true;
                break;
            case 0xb6: //Right shift released
            rightShiftPressed = false;
                break;
            case 0x9c: //Enter
            //FIX: When the terminal scrolls down, i need to push the "enter" key 2 tymes for a new line
            printf("\n\r");
                break;
        }
    }
}

void KeyboardHandler0xe0(uint_8 scanCode)
{
    switch (scanCode)
    {
    case 0x50: //DOWN
        SetCursorPosition(GetCurrentCursorPosition() + VGA_WIDTH);
        break;
    case 0x48: //UP
        SetCursorPosition(GetCurrentCursorPosition() - VGA_WIDTH);
        break;
    default:
        break;
    }
}

void KeyboardHandler(uint_8 scanCode, uint_8 chr)
{
    switch (lastScanCode)
    {
    case 0xe0:
    KeyboardHandler0xe0(scanCode);
        break;
    
    default:
        StandardKeyboardHandler(scanCode, chr);
        break;
    }

    lastScanCode = scanCode;
}