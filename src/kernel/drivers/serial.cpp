#pragma once

//Code from: https://wiki.osdev.org/Serial_Ports

#include "../include/drivers/serial.h"

COMPorts port;

//Initialize Serial at 'P' port
void InitSerial(COMPorts P)
{
    outb(P + 1, 0x00);    // Disable all interrupts
    outb(P + 3, 0x80);    // Enable DLAB (set baud rate divisor)
    outb(P + 0, 0x03);    // Set divisor to 3 (lo byte) 38400 baud
    outb(P + 1, 0x00);    //                  (hi byte)
    outb(P + 3, 0x03);    // 8 bits, no parity, one stop bit
    outb(P + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
    outb(P + 4, 0x0B);    // IRQs enabled, RTS/DSR set

    port = P;
}

//Reciving Data
char ReadCharSerial()
{
    struct whait
    {
        int whaitSerial() {
            return inb(port + 5) & 1;
        }
    };

    whait w;

    while (w.whaitSerial() == 0);

    return inb(port);
}

//Sending Data
void WriteCharSerial(const char a)
{
    struct whait
    {
        int is_transmit_empty() {
            return inb(port + 5) & 0x20;
        }
    };
    whait w;

    while (w.is_transmit_empty() == 0);
 
    outb(port,a);
}

void WriteStringSerial(string str)
{
    for (uint_32 i = 0; i < strlen(str); ++i) {
		WriteCharSerial(str[i]);
	}
}