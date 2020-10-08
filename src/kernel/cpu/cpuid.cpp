#pragma once

#include "../include/cpu/cpuid.h"

void Amd();
void Intel();
void DetectCPU();

MSR msr;

void DetectCPU()
{
	unsigned long ebx, unused;
	cpuid(0, unused, ebx, unused, unused);

	switch(ebx)
    {
    case INTEL_VENDOR_ID: 
        printf("Detected an Intel CPU\n\r");
        Intel();
	break;
    case AMD_VENDOR_ID:
        printf("Detected an AMD CPU\n\r");
        Amd();
	break;
	default:
		printf("Unknown x86 CPU Detected\n\r");
        return;
	break;
	}

    switch (msr.CheckMSR())
    {
    case true:
        printf("MSR Supported\n\r");
        break;
    
    case false:
        printf("MSR Not Supported\n\r");
        break;
    }
}

void Amd()
{
    //TODO: AMD Support
}

void Intel()
{
    //TODO: Intel Support
}