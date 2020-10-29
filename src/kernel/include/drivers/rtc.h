#pragma once

#ifndef _RTC_H_
#define _RTC_H_

#include "../typedef.h"
#include "../ports/Memory/memory.h"
#include "../ports/idt/idt.h"
#include "../drivers/serial.h"

#include <omath.h>

extern volatile bool interrupt;

typedef struct time_t
{
    uint_8 second;
    uint_8 minute;
    uint_8 hour;
    uint_8 day_of_week;
    uint_8 day_of_month;
    uint_8 month;
    uint_8 year;
    uint_8 century;
};

namespace RTC
{
    extern time_t global_time;
    extern bool bcd;

    extern time_t GetTime();
    extern void InitRTC();
    extern void RTCHandler();
}

#endif
