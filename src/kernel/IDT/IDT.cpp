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

extern uint_64 isr0;
extern uint_64 isr1;
extern uint_64 isr2;
extern uint_64 isr3;
extern uint_64 isr4;
extern uint_64 isr5;
extern uint_64 isr6;
extern uint_64 isr7;
extern uint_64 isr8;
extern uint_64 isr9;
extern uint_64 isr10;
extern uint_64 isr11;
extern uint_64 isr12;
extern uint_64 isr13;
extern uint_64 isr14;
extern uint_64 isr15;

extern "C" void LoadIDT();

void IDTinit()
{
    _idt[0].zero = 0;
    _idt[0].offsetLow = (uint_16)(((uint_64)&isr0 & 0x000000000000ffff));
    _idt[0].offsetMid = (uint_16)(((uint_64)&isr0 & 0x00000000ffff0000) >> 16);
    _idt[0].offsetHight = (uint_32)(((uint_64)&isr0 & 0xffffffff00000000) >> 32);
    _idt[0].ist = 0;
    _idt[0].selector = 0x08;
    _idt[0].typesAttr = 0x8e;

    _idt[1].zero = 0;
    _idt[1].offsetLow = (uint_16)(((uint_64)&isr1 & 0x000000000000ffff));
    _idt[1].offsetMid = (uint_16)(((uint_64)&isr1 & 0x00000000ffff0000) >> 16);
    _idt[1].offsetHight = (uint_32)(((uint_64)&isr1 & 0xffffffff00000000) >> 32);
    _idt[1].ist = 0;
    _idt[1].selector = 0x08;
    _idt[1].typesAttr = 0x8e;

    _idt[2].zero = 0;
    _idt[2].offsetLow = (uint_16)(((uint_64)&isr2 & 0x000000000000ffff));
    _idt[2].offsetMid = (uint_16)(((uint_64)&isr2 & 0x00000000ffff0000) >> 16);
    _idt[2].offsetHight = (uint_32)(((uint_64)&isr2 & 0xffffffff00000000) >> 32);
    _idt[2].ist = 0;
    _idt[2].selector = 0x08;
    _idt[2].typesAttr = 0x8e;

    _idt[3].zero = 0;
    _idt[3].offsetLow = (uint_16)(((uint_64)&isr3 & 0x000000000000ffff));
    _idt[3].offsetMid = (uint_16)(((uint_64)&isr3 & 0x00000000ffff0000) >> 16);
    _idt[3].offsetHight = (uint_32)(((uint_64)&isr3 & 0xffffffff00000000) >> 32);
    _idt[3].ist = 0;
    _idt[3].selector = 0x08;
    _idt[3].typesAttr = 0x8e;

    _idt[4].zero = 0;
    _idt[4].offsetLow = (uint_16)(((uint_64)&isr4 & 0x000000000000ffff));
    _idt[4].offsetMid = (uint_16)(((uint_64)&isr4 & 0x00000000ffff0000) >> 16);
    _idt[4].offsetHight = (uint_32)(((uint_64)&isr4 & 0xffffffff00000000) >> 32);
    _idt[4].ist = 0;
    _idt[4].selector = 0x08;
    _idt[4].typesAttr = 0x8e;

    _idt[5].zero = 0;
    _idt[5].offsetLow = (uint_16)(((uint_64)&isr5 & 0x000000000000ffff));
    _idt[5].offsetMid = (uint_16)(((uint_64)&isr5 & 0x00000000ffff0000) >> 16);
    _idt[5].offsetHight = (uint_32)(((uint_64)&isr5 & 0xffffffff00000000) >> 32);
    _idt[5].ist = 0;
    _idt[5].selector = 0x08;
    _idt[5].typesAttr = 0x8e;

    _idt[6].zero = 0;
    _idt[6].offsetLow = (uint_16)(((uint_64)&isr6 & 0x000000000000ffff));
    _idt[6].offsetMid = (uint_16)(((uint_64)&isr6 & 0x00000000ffff0000) >> 16);
    _idt[6].offsetHight = (uint_32)(((uint_64)&isr6 & 0xffffffff00000000) >> 32);
    _idt[6].ist = 0;
    _idt[6].selector = 0x08;
    _idt[6].typesAttr = 0x8e;

    _idt[7].zero = 0;
    _idt[7].offsetLow = (uint_16)(((uint_64)&isr7 & 0x000000000000ffff));
    _idt[7].offsetMid = (uint_16)(((uint_64)&isr7 & 0x00000000ffff0000) >> 16);
    _idt[7].offsetHight = (uint_32)(((uint_64)&isr7 & 0xffffffff00000000) >> 32);
    _idt[7].ist = 0;
    _idt[7].selector = 0x08;
    _idt[7].typesAttr = 0x8e;

    _idt[8].zero = 0;
    _idt[8].offsetLow = (uint_16)(((uint_64)&isr8 & 0x000000000000ffff));
    _idt[8].offsetMid = (uint_16)(((uint_64)&isr8 & 0x00000000ffff0000) >> 16);
    _idt[8].offsetHight = (uint_32)(((uint_64)&isr8 & 0xffffffff00000000) >> 32);
    _idt[8].ist = 0;
    _idt[8].selector = 0x08;
    _idt[8].typesAttr = 0x8e;

    _idt[9].zero = 0;
    _idt[9].offsetLow = (uint_16)(((uint_64)&isr9 & 0x000000000000ffff));
    _idt[9].offsetMid = (uint_16)(((uint_64)&isr9 & 0x00000000ffff0000) >> 16);
    _idt[9].offsetHight = (uint_32)(((uint_64)&isr9 & 0xffffffff00000000) >> 32);
    _idt[9].ist = 0;
    _idt[9].selector = 0x08;
    _idt[9].typesAttr = 0x8e;

    _idt[10].zero = 0;
    _idt[10].offsetLow = (uint_16)(((uint_64)&isr10 & 0x000000000000ffff));
    _idt[10].offsetMid = (uint_16)(((uint_64)&isr10 & 0x00000000ffff0000) >> 16);
    _idt[10].offsetHight = (uint_32)(((uint_64)&isr10 & 0xffffffff00000000) >> 32);
    _idt[10].ist = 0;
    _idt[10].selector = 0x08;
    _idt[10].typesAttr = 0x8e;

    _idt[11].zero = 0;
    _idt[11].offsetLow = (uint_16)(((uint_64)&isr11 & 0x000000000000ffff));
    _idt[11].offsetMid = (uint_16)(((uint_64)&isr11 & 0x00000000ffff0000) >> 16);
    _idt[11].offsetHight = (uint_32)(((uint_64)&isr11 & 0xffffffff00000000) >> 32);
    _idt[11].ist = 0;
    _idt[11].selector = 0x08;
    _idt[11].typesAttr = 0x8e;

    _idt[12].zero = 0;
    _idt[12].offsetLow = (uint_16)(((uint_64)&isr12 & 0x000000000000ffff));
    _idt[12].offsetMid = (uint_16)(((uint_64)&isr12 & 0x00000000ffff0000) >> 16);
    _idt[12].offsetHight = (uint_32)(((uint_64)&isr12 & 0xffffffff00000000) >> 32);
    _idt[12].ist = 0;
    _idt[12].selector = 0x08;
    _idt[12].typesAttr = 0x8e;

    _idt[13].zero = 0;
    _idt[13].offsetLow = (uint_16)(((uint_64)&isr13 & 0x000000000000ffff));
    _idt[13].offsetMid = (uint_16)(((uint_64)&isr13 & 0x00000000ffff0000) >> 16);
    _idt[13].offsetHight = (uint_32)(((uint_64)&isr13 & 0xffffffff00000000) >> 32);
    _idt[13].ist = 0;
    _idt[13].selector = 0x08;
    _idt[13].typesAttr = 0x8e;

    _idt[14].zero = 0;
    _idt[14].offsetLow = (uint_16)(((uint_64)&isr14 & 0x000000000000ffff));
    _idt[14].offsetMid = (uint_16)(((uint_64)&isr14 & 0x00000000ffff0000) >> 16);
    _idt[14].offsetHight = (uint_32)(((uint_64)&isr14 & 0xffffffff00000000) >> 32);
    _idt[14].ist = 0;
    _idt[14].selector = 0x08;
    _idt[14].typesAttr = 0x8e;

    _idt[15].zero = 0;
    _idt[15].offsetLow = (uint_16)(((uint_64)&isr15 & 0x000000000000ffff));
    _idt[15].offsetMid = (uint_16)(((uint_64)&isr15 & 0x00000000ffff0000) >> 16);
    _idt[15].offsetHight = (uint_32)(((uint_64)&isr15 & 0xffffffff00000000) >> 32);
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
extern "C" void isr0Handler()
{
    //System Timer
    outb(0x20, 0x20);
}

extern "C" void isr1Handler()
{
    //Keyboard
    uint_8 scanCode = inb(0x60);
    uint_8 chr = 0;

    if(scanCode < 0x3A)
        chr = KBSet1::ScanCodeLookupTable[scanCode];

    if(MainKeyboardHandler != 0)
        MainKeyboardHandler(scanCode, chr);

    outb(0x20, 0x20);
    outb(0xa0, 0x20);
}

extern "C" void isr2Handler()
{
    //PIC8259B
    outb(0x20, 0x20);
}

extern "C" void isr3Handler()
{
    //COM2, COM 4
    outb(0x20, 0x20);
}

extern "C" void isr4Handler()
{
    //COM1, COM 3
    outb(0x20, 0x20);
}

extern "C" void isr5Handler()
{
    //LPT 2 OR AUDIO CARD
    outb(0x20, 0x20);
}

extern "C" void isr6Handler()
{
    //Floppy Disk
    outb(0x20, 0x20);
}

extern "C" void isr7Handler()
{
    //LPT1 AND LPT 3
    outb(0x20, 0x20);
}

//Pic B
extern "C" void isr8Handler()
{
    //RTC
    outb(0xA0, 0x20);
    outb(0x20, 0x20);
}

extern "C" void isr9Handler()
{
    //IRQ2 redirect
    outb(0xA0, 0x20);
    outb(0x20, 0x20);
}

extern "C" void isr10Handler()
{
    //RTC
    outb(0xA0, 0x20);
    outb(0x20, 0x20);
}

extern "C" void isr11Handler()
{
    //RTC
    outb(0xA0, 0x20);
    outb(0x20, 0x20);
}

extern "C" void isr12Handler()
{
    //PS2 MOUSE
    outb(0xA0, 0x20);
    outb(0x20, 0x20);
}

extern "C" void isr13Handler()
{
    //Co math processor
    outb(0xA0, 0x20);
    outb(0x20, 0x20);
}

extern "C" void isr14Handler()
{
    //Primary ide
    outb(0xA0, 0x20);
    outb(0x20, 0x20);
}

extern "C" void isr15Handler()
{
    //Secondary ide
    outb(0xA0, 0x20);
    outb(0x20, 0x20);
}