#include "../include/drivers/pit.h"
#include "../include/kprint.h"

uint_64 counter;
// Code from: http://kernelx.weebly.com/programmable-interval-timer.html

//Channel0
void TimerSet(int hz)
{
    int div = 1193180 / hz;
    outb(PIT_CMDREG, 0xb6);
    outb(PIT_CHANNEL2, (unsigned char) (div));
    outb(PIT_CHANNEL2, (unsigned char) (div >> 8)); 
}

//Channel2
void SpeakerSet(int hz)
{
    int div = 1193180 / hz;
    outb(PIT_CMDREG, 0xb6);
    outb(PIT_CHANNEL2, (unsigned char) (div));
    outb(PIT_CHANNEL2, (unsigned char) (div >> 8));
}

void wait(int count)
{
    unsigned long wait_till;    //This is addition of count and the current no of ticks

    wait_till = counter + count;
    while(counter < wait_till) //loops until the given period has been reached
    {
        asm volatile ("int $0x00");
    }
}

void PITHandler()
{
    counter++;
}

void TimerInit()
{
    MainPITHandler = PITHandler;
}
