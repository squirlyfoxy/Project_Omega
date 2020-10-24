// License: See floppy.cpp

#pragma once

#ifndef _FLOPPY_H
#define _FLOPPY_H

#define PRIMARY_FLOPPY_CONTROLLER   0x03F0

//Floppy Registers
enum FloppyRegisters // (The most Importants)
{
    FLOPPY_DOR  = 2,  // Digital output register
    FLOPPY_MSR  = 4,  // Master status register, read only
    FLOPPY_FIFO = 5,  // Data FIFO, in DMA operation for commands
    FLOPPY_CCR  = 7   // Configuration control register, write only
};

//Floppy Commands
enum FloppyCommands // (The most Importants)
{
    CMD_SPECIFY = 3,            // SPECIFY
    CMD_WRITE_DATA = 5,         // WRITE DATA
    CMD_READ_DATA = 6,          // READ DATA
    CMD_RECALIBRATE = 7,        // RECALIBRATE
    CMD_SENSE_INTERRUPT = 8,    // SENSE INTERRUPT
    CMD_SEEK = 15               // SEEK
};

#endif
