#pragma once

#ifndef _CMOS_H_
#define _CMOS_H_

#define CMOS_ADDREG     0x70
#define CMOS_DATAREG    0x71

#include "../ports/IO.h"

unsigned char ReadCMOS(unsigned char cmos_register);
unsigned short GetMenorySize();

#endif