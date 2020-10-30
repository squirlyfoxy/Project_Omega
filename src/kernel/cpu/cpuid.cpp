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
    ActivateSSE();
}

//Get AL value
uint_8 GetALValue()
{
    uint_8 val;

    //Assembly
    asm volatile("movb %%al, %0" : "=r" (val));

    return val;
}

//Get AH value
uint_8 GetAHValue()
{
    uint_8 val;

    //Assembly
    asm volatile("movb %%ah, %0" : "=r" (val));

    return val;
}

//Get CL value
uint_8 GetCLValue()
{
    uint_8 val;

    //Assembly
    asm volatile("movb %%cl, %0" : "=r" (val));

    return val;
}

//Get CH value
uint_8 GetCHValue()
{
    uint_8 val;

    //Assembly
    asm volatile("movb %%ch, %0" : "=r" (val));

    return val;
}

//Get BL value
uint_8 GetBLValue()
{
    uint_8 val;

    //Assembly
    asm volatile("movb %%bl, %0" : "=r" (val));

    return val;
}

//Get BH value
uint_8 GetBHValue()
{
    uint_8 val;

    //Assembly
    asm volatile("movb %%bh, %0" : "=r" (val));

    return val;
}