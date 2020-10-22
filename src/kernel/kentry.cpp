/*
    Copyright (c) 2020 - Project Omega

    Programmer: squirlyfoxy

    Summary: See TODO
*/

/*
    TODO:
    Cosa deve fare questa parte di kernel?
    - Inizializza IDT (Done)
    - Memory management di base (In Development)
    - Inizializza File System
        - Capire dove inizia la root, salvare questo dato in un gruppo di celle in memoria che saranno in sola lettura
        - Scansione della root e trovare il programma di init che procederà all'inizializzazzione di tutte le altre cose
        - Eseguire il programma di init passandogli il comando sulla cpu (ritornerà un codice di errore, se necessario)
        - Controlla il codice di errore, se è tutto ok passa il controllo all'utente; altrimenti kernel panic
    */
#include "include/kprint.h"
#include "include/string.h"
#include "include/ports/idt/idt.h"
#include "include/ports/Keyboard/keyboard.h"
#include "include/ports/Memory/memory_map.h"
#include "include/ports/Memory/heap.h"
#include "include/drivers/serial.h"
#include "include/drivers/fs/disks.h"
#include "include/cpu/cpuid.h"

extern "C" void _start()
{   
    ClearScreen();

    printf("Initializing IDT: ");
    IDTinit(); //Initialize Interrupts Descriptor Table
    printf("(OK) \n\r");

    printf("Initializing Heap: ");
    InitHeap(0x100000, 0x100000);
    printf("(OK) \n\r");
    
    printf("Initializing Serial Ports (COM1): ");
    InitSerial(COM1);
    printf("(OK) \n\r");

    WriteStringSerial("Project Omega Initializated!");

    CheckDisks();

    MainKeyboardHandler = KeyboardHandler;
    
    return;
}