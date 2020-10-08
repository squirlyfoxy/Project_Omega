#ifndef _CPUID_H
#define _CPUID_H

#include "../../kprint.cpp"
#include "../typedef.h"
#include "msr.h"

#define INTEL_VENDOR_ID 0x756e6547
#define AMD_VENDOR_ID 0x68747541

#define cpuid(in, a, b, c, d) __asm__("cpuid": "=a" (a), "=b" (b), "=c" (c), "=d" (d) : "a" (in));

char* cpuName;

struct MSR
{
    bool CheckMSR()
    {
        unsigned long eax, ebx, _unused; // a = eax, d = edx
        cpuid(1, eax, ebx, _unused, _unused);
        return ebx & CPUID_FLAG_MSR;
    }
};

#endif