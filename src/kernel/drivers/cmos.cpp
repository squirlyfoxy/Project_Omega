#include "../include/drivers/cmos.h"

//Code from: http://kernelx.weebly.com/cmos.html

//Read CMOS register
unsigned char ReadCMOS(unsigned char cmos_register)
{
    unsigned char data;
    outb(CMOS_ADDREG, cmos_register);
    data = inb(CMOS_DATAREG);
    return data;
}

unsigned short GetMenorySize()
{
    unsigned short memory; 
    unsigned char low, high; 
    low =ReadCMOS(0x30);   
    high=ReadCMOS(0x31);

    memory = low | high << 8;
    return memory;
}

//TODO: RTC