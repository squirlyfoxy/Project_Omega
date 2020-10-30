#pragma once

#ifndef _CPUID_H
#define _CPUID_H

#include "../typedef.h"
#include "msr.h"

#define INTEL_VENDOR_ID 0x756e6547
#define AMD_VENDOR_ID 0x68747541

#define cpuid(in, a, b, c, d) __asm__("cpuid": "=a" (a), "=b" (b), "=c" (c), "=d" (d) : "a" (in));

struct MSR
{
    bool CheckMSR()
    {
        unsigned long eax, ebx, _unused; // a = eax, d = edx
        cpuid(1, eax, ebx, _unused, _unused);
        return ebx & CPUID_FLAG_MSR;
    }
};

extern "C" void ActivateSSE();

void Amd();
void Intel();
uint_16 DetectCPU();

uint_8 GetALValue();
uint_8 GetAHValue();
uint_8 GetCLValue();
uint_8 GetCHValue();
uint_8 GetBLValue();
uint_8 GetBHValue();

#endif