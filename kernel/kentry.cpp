/*
    Copyright (c) 2020 - Project Omega

    Programmer: squirlyfoxy

    Summary: See TODO
*/

/*
    TODO:
    Cosa deve fare questa parte di kernel?
    - Inizializza IDT (Done)
    - Memory management di base
    - Inizializza File System
        - Capire dove inizia la root, salvare questo dato in un gruppo di celle in memoria che saranno in sola lettura
        - Scansione della root e trovare il programma di init che procederà all'inizializzazzione di tutte le altre cose
        - Eseguire il programma di init passandogli il comando sulla cpu (ritornerà un codice di errore, se necessario)
        - Controlla il codice di errore, se è tutto ok passa il controllo all'utente; altrimenti kernel panic
    */
#include "kprint.cpp"
#include "IDT/IDT.cpp"

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
            SetCursorPosition(CurrentCursorPosition - 1);
            PrintChar(' ');
            SetCursorPosition(CurrentCursorPosition - 1);
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
            printf("\n\r");
                break;
        }
    }
}

void KeyboardHandler0xe0(uint_8 scanCode)
{
    switch (scanCode)
    {
    case 0x50:
        SetCursorPosition(CurrentCursorPosition + VGA_WIDTH);
        break;
    case 0x48:
        SetCursorPosition(CurrentCursorPosition - VGA_WIDTH);
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

extern "C" void _start()
{   
    ClearScreen();

    IDTinit(); //Initialize Interrupts Descriptor Table

    MainKeyboardHandler = KeyboardHandler;

    //HlT System (for now, it's just a test)
    for(;;)
    {
        asm("hlt");
    }

    return;
}