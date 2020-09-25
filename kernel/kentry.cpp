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
#include "string.cpp"
#include "IDT/IDT.cpp"
#include "IDT/Keyboard/Keyboard.cpp"

extern "C" void _start()
{   
    ClearScreen();

    IDTinit(); //Initialize Interrupts Descriptor Table

    MainKeyboardHandler = KeyboardHandler;

    printf(itoa(100));

    //HlT System (for now, it's just a test)
    for(;;)
    {
        asm("hlt");
    }

    return;
}