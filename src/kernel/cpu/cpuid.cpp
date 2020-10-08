#include "../include/cpu/cpuid.h"

MSR msr;

uint_16 DetectCPU()
{
    uint_16 toRet;

	unsigned long ebx, unused;
	cpuid(0, unused, ebx, unused, unused);

	switch(ebx)
    {
    case INTEL_VENDOR_ID: 
        toRet = INTEL_VENDOR_ID;
        Intel();
	break;
    case AMD_VENDOR_ID:
        toRet = AMD_VENDOR_ID;
        Amd();
	break;
	default:
		toRet = 0;
	break;
	}

    return toRet;
}

void Amd()
{
    //TODO: AMD Support
}

void Intel()
{
    //TODO: Intel Support
}