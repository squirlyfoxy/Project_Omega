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
#include "kprint.cpp"
#include "string.cpp"
#include "IDT/IDT.cpp"
#include "IDT/Keyboard/Keyboard.cpp"
#include "MEM/MemoryMap.cpp"
#include "MEM/Heap.cpp"
#include "./drivers/serial.cpp"
#include "./cpu/cpuid.cpp"

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

    DetectCPU();

    WriteStringSerial("Project Omega Initializated!");

    //MainKeyboardHandler = KeyboardHandler;
    MemoryMapEntry** usableMemoryMaps = GetUsableMemoryRegions();

    uint_64* TestAddress = (uint_64*)(malloc(0x08));
    *TestAddress = 12345678;
    printf(itoa(*TestAddress)); printf("\n\r"); //12345678

    uint_64* TestAddress2 = (uint_64*)(realloc(TestAddress, 0x08));
    printf(itoa(*TestAddress2)); printf("\n\r"); //12345678

    uint_64* TestAddress3 = (uint_64*)(calloc(0x08));
    printf(itoa(*TestAddress3)); printf("\n\r"); //0
    return;
}