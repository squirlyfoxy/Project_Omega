#ifndef _CPUID_H
#define _CPUID_H

#include "../../kprint.cpp"
#include "../typedef.h"

#define cpuid(in, a, b, c, d) __asm__("cpuid": "=a" (a), "=b" (b), "=c" (c), "=d" (d) : "a" (in));

#define INTEL_VENDOR_ID 0x756e6547
#define AMD_VENDOR_ID 0x68747541

uint_8 cpuVendor;
char* cpuName;

#endif