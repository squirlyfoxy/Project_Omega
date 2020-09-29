#pragma once

#include "../include/cpu/cpuid.h"

#define cpuid(in, a, b, c, d) __asm__("cpuid": "=a" (a), "=b" (b), "=c" (c), "=d" (d) : "a" (in));

void InitVendor();

void DetectCPU()
{
	unsigned long ebx, unused;
	cpuid(0, unused, ebx, unused, unused);
	switch(ebx)
    {
        case INTEL_VENDOR_ID: 
            printf("Detected an Intel CPU\n\r");
            cpuVendor = 0;
		break;
        case AMD_VENDOR_ID:
            printf("Detected an AMD CPU\n\r");
            cpuVendor = 1;
	    break;
		default:
		    printf("Unknown x86 CPU Detected\n\r");
            cpuVendor = 2;
		break;
	}

    //Initialize vendor
    InitVendor();
}

void InitVendor()
{
    struct vendInit
    {
        void Intel()
        {
            //TODO: Initialize Intel CPU
        }

        void Amd()
        {
            //TODO: Initialize AMD CPU
        }
    };

    vendInit vI;

    switch (cpuVendor)
    {
        case 0:
            //Intel CPU
            vI.Intel();
        break;
        case 1:
            //Amd CPU
            vI.Amd();
        break;
        default:
            break;
    }
}