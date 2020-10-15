#pragma once

#ifndef _8259_H
#define _8259_H

#include "../typedef.h"
#include "IO.h"

//PIC Chip: https://wiki.osdev.org/PIC
#define PIC1_COMMAND 0x20
#define PIC1_DATA 0x21
#define PIC2_COMMAND 0xa0
#define PIC2_DATA 0xa1

//Inizialization
#define ICW1_INIT 0x10
#define ICW1_ICW4 0x01
#define ICW4_8086 0x01

//EOI
#define PIC_EOI		0x20    //End of intterrupt port

void RemapPIC();
void PICSendEOI(uint_8 irq);

#endif