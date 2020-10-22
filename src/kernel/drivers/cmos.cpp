#include "../include/drivers/cmos.h"

//Read CMOS register
unsigned char ReadCMOS(unsigned char cmos_register)
{
   unsigned char cmos_data;
   
    cli(); //Disable Interrupts

    outb(0x70, ((inb(0x70) & 0xe0) | (cmos_register & 0x31))); // keep the top 3 bits, alter the last 5
    cmos_data = inb (0x71);

    sti(); //Enable Interrupts
    return(cmos_data);   // returns only after we have the data in custody
}

//TODO: RTC