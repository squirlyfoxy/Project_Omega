#pragma once

#ifndef _SERIAL_H
#define _SERIAL_H

#include "../typedef.h"
#include "../ports/IO.h"
#include "../string.h"

enum COMPorts
{
    COM1 = 0x3F8,
    COM2 = 0x2F8,
    COM3 = 0x3E8,
    COM4 = 0x2E8
};

void InitSerial(COMPorts P);
char ReadCharSerial();
void WriteCharSerial(const char a);
void WriteStringSerial(string str);

#endif