#pragma once

#ifndef _CMOS_H_
#define _CMOS_H_

#define CMOS_ADDREG     0x70
#define CMOS_DATAREG    0x71

#include "../ports/IO.h"
#include "rtc.h"

unsigned char ReadCMOS(unsigned char cmos_register);
void WriteCMOS(unsigned char reg, unsigned char value);

#endif
