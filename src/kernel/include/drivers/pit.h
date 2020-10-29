#pragma once

#ifndef _PIT_H
#define _PIT_H

#include "../ports/idt/idt.h"
#include "../ports/IO.h"
#include "../typedef.h"

#define PIT_CHANNEL0      0x40  //PIT Channel 0's Data Register Port
//#define PIT_CHANNEL1      0x41  //PIT Channels 1's Data Register Port, obsolete
#define PIT_CHANNEL2      0x42  //PIT Channels 2's Data Register Port
#define PIT_CMDREG        0x43  //PIT Chip's Command Register Port

extern uint_64 counter;

void TimerSet(int hz);
void SpeakerSet(int hz);
void TimerInit();
void wait(int count);

#endif
