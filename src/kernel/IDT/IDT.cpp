#include "../include/ports/idt/idt.h"

void (*MainKeyboardHandler) (uint_8 scanCode, uint_8 chr);

//Interrupt Descriptor Table
struct IDT64
{
    uint_16 offsetLow;
    uint_16 selector;
    uint_8  ist;
    uint_8  typesAttr;
    uint_16 offsetMid;
    uint_32 offsetHight;
    uint_32 zero;
};

extern IDT64 _idt[256];

extern uint_64 irq0;
extern uint_64 irq1;
extern uint_64 irq2;
extern uint_64 irq3;
extern uint_64 irq4;
extern uint_64 irq5;
extern uint_64 irq6;
extern uint_64 irq7;
extern uint_64 irq8;
extern uint_64 irq9;
extern uint_64 irq10;
extern uint_64 irq11;
extern uint_64 irq12;
extern uint_64 irq13;
extern uint_64 irq14;
extern uint_64 irq15;

extern "C" void LoadIDT();

void IDTinit()
{
    _idt[0].zero = 0;
    _idt[0].offsetLow = (uint_16)(((uint_64)&irq0 & 0x000000000000ffff));
    _idt[0].offsetMid = (uint_16)(((uint_64)&irq0 & 0x00000000ffff0000) >> 16);
    _idt[0].offsetHight = (uint_32)(((uint_64)&irq0 & 0xffffffff00000000) >> 32);
    _idt[0].ist = 0;
    _idt[0].selector = 0x08;
    _idt[0].typesAttr = 0x8e;

    _idt[1].zero = 0;
    _idt[1].offsetLow = (uint_16)(((uint_64)&irq1 & 0x000000000000ffff));
    _idt[1].offsetMid = (uint_16)(((uint_64)&irq1 & 0x00000000ffff0000) >> 16);
    _idt[1].offsetHight = (uint_32)(((uint_64)&irq1 & 0xffffffff00000000) >> 32);
    _idt[1].ist = 0;
    _idt[1].selector = 0x08;
    _idt[1].typesAttr = 0x8e;

    _idt[2].zero = 0;
    _idt[2].offsetLow = (uint_16)(((uint_64)&irq2 & 0x000000000000ffff));
    _idt[2].offsetMid = (uint_16)(((uint_64)&irq2 & 0x00000000ffff0000) >> 16);
    _idt[2].offsetHight = (uint_32)(((uint_64)&irq2 & 0xffffffff00000000) >> 32);
    _idt[2].ist = 0;
    _idt[2].selector = 0x08;
    _idt[2].typesAttr = 0x8e;

    _idt[3].zero = 0;
    _idt[3].offsetLow = (uint_16)(((uint_64)&irq3 & 0x000000000000ffff));
    _idt[3].offsetMid = (uint_16)(((uint_64)&irq3 & 0x00000000ffff0000) >> 16);
    _idt[3].offsetHight = (uint_32)(((uint_64)&irq3 & 0xffffffff00000000) >> 32);
    _idt[3].ist = 0;
    _idt[3].selector = 0x08;
    _idt[3].typesAttr = 0x8e;

    _idt[4].zero = 0;
    _idt[4].offsetLow = (uint_16)(((uint_64)&irq4 & 0x000000000000ffff));
    _idt[4].offsetMid = (uint_16)(((uint_64)&irq4 & 0x00000000ffff0000) >> 16);
    _idt[4].offsetHight = (uint_32)(((uint_64)&irq4 & 0xffffffff00000000) >> 32);
    _idt[4].ist = 0;
    _idt[4].selector = 0x08;
    _idt[4].typesAttr = 0x8e;

    _idt[5].zero = 0;
    _idt[5].offsetLow = (uint_16)(((uint_64)&irq5 & 0x000000000000ffff));
    _idt[5].offsetMid = (uint_16)(((uint_64)&irq5 & 0x00000000ffff0000) >> 16);
    _idt[5].offsetHight = (uint_32)(((uint_64)&irq5 & 0xffffffff00000000) >> 32);
    _idt[5].ist = 0;
    _idt[5].selector = 0x08;
    _idt[5].typesAttr = 0x8e;

    _idt[6].zero = 0;
    _idt[6].offsetLow = (uint_16)(((uint_64)&irq6 & 0x000000000000ffff));
    _idt[6].offsetMid = (uint_16)(((uint_64)&irq6 & 0x00000000ffff0000) >> 16);
    _idt[6].offsetHight = (uint_32)(((uint_64)&irq6 & 0xffffffff00000000) >> 32);
    _idt[6].ist = 0;
    _idt[6].selector = 0x08;
    _idt[6].typesAttr = 0x8e;

    _idt[7].zero = 0;
    _idt[7].offsetLow = (uint_16)(((uint_64)&irq7 & 0x000000000000ffff));
    _idt[7].offsetMid = (uint_16)(((uint_64)&irq7 & 0x00000000ffff0000) >> 16);
    _idt[7].offsetHight = (uint_32)(((uint_64)&irq7 & 0xffffffff00000000) >> 32);
    _idt[7].ist = 0;
    _idt[7].selector = 0x08;
    _idt[7].typesAttr = 0x8e;

    _idt[8].zero = 0;
    _idt[8].offsetLow = (uint_16)(((uint_64)&irq8 & 0x000000000000ffff));
    _idt[8].offsetMid = (uint_16)(((uint_64)&irq8 & 0x00000000ffff0000) >> 16);
    _idt[8].offsetHight = (uint_32)(((uint_64)&irq8 & 0xffffffff00000000) >> 32);
    _idt[8].ist = 0;
    _idt[8].selector = 0x08;
    _idt[8].typesAttr = 0x8e;

    _idt[9].zero = 0;
    _idt[9].offsetLow = (uint_16)(((uint_64)&irq9 & 0x000000000000ffff));
    _idt[9].offsetMid = (uint_16)(((uint_64)&irq9 & 0x00000000ffff0000) >> 16);
    _idt[9].offsetHight = (uint_32)(((uint_64)&irq9 & 0xffffffff00000000) >> 32);
    _idt[9].ist = 0;
    _idt[9].selector = 0x08;
    _idt[9].typesAttr = 0x8e;

    _idt[10].zero = 0;
    _idt[10].offsetLow = (uint_16)(((uint_64)&irq10 & 0x000000000000ffff));
    _idt[10].offsetMid = (uint_16)(((uint_64)&irq10 & 0x00000000ffff0000) >> 16);
    _idt[10].offsetHight = (uint_32)(((uint_64)&irq10 & 0xffffffff00000000) >> 32);
    _idt[10].ist = 0;
    _idt[10].selector = 0x08;
    _idt[10].typesAttr = 0x8e;

    _idt[11].zero = 0;
    _idt[11].offsetLow = (uint_16)(((uint_64)&irq11 & 0x000000000000ffff));
    _idt[11].offsetMid = (uint_16)(((uint_64)&irq11 & 0x00000000ffff0000) >> 16);
    _idt[11].offsetHight = (uint_32)(((uint_64)&irq11 & 0xffffffff00000000) >> 32);
    _idt[11].ist = 0;
    _idt[11].selector = 0x08;
    _idt[11].typesAttr = 0x8e;

    _idt[12].zero = 0;
    _idt[12].offsetLow = (uint_16)(((uint_64)&irq12 & 0x000000000000ffff));
    _idt[12].offsetMid = (uint_16)(((uint_64)&irq12 & 0x00000000ffff0000) >> 16);
    _idt[12].offsetHight = (uint_32)(((uint_64)&irq12 & 0xffffffff00000000) >> 32);
    _idt[12].ist = 0;
    _idt[12].selector = 0x08;
    _idt[12].typesAttr = 0x8e;

    _idt[13].zero = 0;
    _idt[13].offsetLow = (uint_16)(((uint_64)&irq13 & 0x000000000000ffff));
    _idt[13].offsetMid = (uint_16)(((uint_64)&irq13 & 0x00000000ffff0000) >> 16);
    _idt[13].offsetHight = (uint_32)(((uint_64)&irq13 & 0xffffffff00000000) >> 32);
    _idt[13].ist = 0;
    _idt[13].selector = 0x08;
    _idt[13].typesAttr = 0x8e;

    _idt[14].zero = 0;
    _idt[14].offsetLow = (uint_16)(((uint_64)&irq14 & 0x000000000000ffff));
    _idt[14].offsetMid = (uint_16)(((uint_64)&irq14 & 0x00000000ffff0000) >> 16);
    _idt[14].offsetHight = (uint_32)(((uint_64)&irq14 & 0xffffffff00000000) >> 32);
    _idt[14].ist = 0;
    _idt[14].selector = 0x08;
    _idt[14].typesAttr = 0x8e;

    _idt[15].zero = 0;
    _idt[15].offsetLow = (uint_16)(((uint_64)&irq15 & 0x000000000000ffff));
    _idt[15].offsetMid = (uint_16)(((uint_64)&irq15 & 0x00000000ffff0000) >> 16);
    _idt[15].offsetHight = (uint_32)(((uint_64)&irq15 & 0xffffffff00000000) >> 32);
    _idt[15].ist = 0;
    _idt[15].selector = 0x08;
    _idt[15].typesAttr = 0x8e;

    //TODO: Fill the remaining spaces

    RemapPIC();

    outb(0x21, 0xfd);
    outb(0xa1, 0xff);

    LoadIDT();
}

//SRC: https://it.wikipedia.org/wiki/Interrupt_request
//Pic A
extern "C" void irq0Handler()
{
    //System Timer
    PICSendEOI(0);
}

extern "C" void irq1Handler()
{
    //Keyboard
    uint_8 scanCode = inb(0x60);
    uint_8 chr = 0;

    if(scanCode < 0x3A)
        chr = KBSet1::ScanCodeLookupTable[scanCode];

    if(MainKeyboardHandler != 0)
        MainKeyboardHandler(scanCode, chr);

    PICSendEOI(1);
}

extern "C" void irq2Handler()
{
    //PIC8259B
    PICSendEOI(2);
}

extern "C" void irq3Handler()
{
    //COM2, COM 4
    PICSendEOI(3);
}

extern "C" void irq4Handler()
{
    //COM1, COM 3
    PICSendEOI(4);
}

extern "C" void irq5Handler()
{
    //LPT 2 OR AUDIO CARD
    PICSendEOI(5);
}

extern "C" void irq6Handler()
{
    //Floppy Disk
    PICSendEOI(6);
}

extern "C" void irq7Handler()
{
    //LPT1 AND LPT 3
    PICSendEOI(7);
}

//Pic B
extern "C" void irq8Handler()
{
    //RTC
    PICSendEOI(8);
}

extern "C" void irq9Handler()
{
    //IRQ2 redirect
    PICSendEOI(9);
}

extern "C" void irq10Handler()
{
    //RTC
    PICSendEOI(10);
}

extern "C" void irq11Handler()
{
    //RTC
    PICSendEOI(11);
}

extern "C" void irq12Handler()
{
    //PS2 MOUSE
    PICSendEOI(12);
}

extern "C" void irq13Handler()
{
    //Co math processor
    PICSendEOI(13);
}

extern "C" void irq14Handler()
{
    //Primary ide
    PICSendEOI(14);
}

extern "C" void irq15Handler()
{
    //Secondary ide
    PICSendEOI(15);
}