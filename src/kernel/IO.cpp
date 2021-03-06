#include "./include/ports/IO.h"

//Disable Interrupts
void cli()
{
    asm volatile ("cli");
}

void sti()
{
    asm volatile ("sti");
}

void outb(unsigned short port, unsigned char val)
{
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

unsigned char inb(unsigned short port)
{
    unsigned char toReturn;

    asm volatile ("inb %1, %0"
        : "=a"(toReturn)
        : "Nd"(port));

    return toReturn;
}
