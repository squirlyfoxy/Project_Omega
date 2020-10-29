#include "../include/drivers/cmos.h"

//Code from: http://kernelx.weebly.com/cmos.html
volatile bool interrupt;

//Read CMOS register
unsigned char ReadCMOS(unsigned char cmos_register)
{
    unsigned char data;
    outb(CMOS_ADDREG, cmos_register);
    data = inb(CMOS_DATAREG);
    return data;
}

//Write a value to CMOS
void WriteCMOS(unsigned char reg, unsigned char value)
{
    outb(CMOS_ADDREG, reg);
    outb(CMOS_DATAREG, value);
}

//RTC Timer
namespace RTC
{
    //Code from: https://forum.osdev.org/viewtopic.php?f=1&t=17433
    time_t global_time;
    bool bcd;

    void RTCHandler()
    {
        //if(ReadCMOS(0x0C) & 0x10)
        //{
            if(bcd)
            {
                global_time.second = CONVERT::bcd2bin(ReadCMOS(0x00));
                global_time.minute = CONVERT::bcd2bin(ReadCMOS(0x02));
                global_time.hour   = CONVERT::bcd2bin(ReadCMOS(0x04));
                global_time.month  = CONVERT::bcd2bin(ReadCMOS(0x08));
                global_time.year   = CONVERT::bcd2bin(ReadCMOS(0x09));
                global_time.day_of_week  = CONVERT::bcd2bin(ReadCMOS(0x06));
                global_time.day_of_month = CONVERT::bcd2bin(ReadCMOS(0x07));
                global_time.century = CONVERT::bcd2bin(ReadCMOS(0x32));
            }else 
            {
                global_time.second = ReadCMOS(0x00);
                global_time.minute = ReadCMOS(0x02);
                global_time.hour   = ReadCMOS(0x04);
                global_time.month  = ReadCMOS(0x08);
                global_time.year   = ReadCMOS(0x09);
                global_time.day_of_week  = ReadCMOS(0x06);
                global_time.day_of_month = ReadCMOS(0x07);
                global_time.century = ReadCMOS(0x32);
            }
        //}
    }

    time_t GetTime()
    {
        asm volatile ("int $0x08"); // call IRQ8

        //Whait IRQ8
        for(int i = 0; i < 100; i++); //TODO: Be Whait()

        return global_time;
    }

    void InitRTC()
    {
        unsigned char status;
        /*
        cli();
        outb(0x70, 0x8b);
        char prev = inb(0x71);
        outb(0x70, 0x8b);
        outb(0x71, prev | 0x40);
        sti();*/

        status = ReadCMOS(0x0B);
        status |=  0x02;             // 24 hour clock
        status |=  0x10;             // update ended interrupts
        status &= ~0x20;             // no alarm interrupts
        status &= ~0x40;             // no periodic interrupt
        bcd     =  !(status & 0x04); // check if data type is BCD
        WriteCMOS(0x0B, status);

        ReadCMOS(0x0C);

        //Init RTC Handler
        MainRTCHandler = RTCHandler;
    }
}
