#include "../include/cpu/cpuid.h"

void DoAmd();
void DoIntel();
void DetectCPUFamilyAndModel();
void DetectCPUName();

MSR msr;
cpu CPUinfos;

void DetectCPUFamilyAndModel()
{
    //Detect cpu family & model
    //Code from https://github.com/mallardtheduck/osdev/blob/master/src/kernel/cpuid.c
    unsigned long extended, eax, ebx, ecx, edx, unused;
	int family, model, stepping, reserved;
	cpuid(1, eax, unused, unused, unused);
	model = (eax >> 4) & 0xf;
	family = (eax >> 8) & 0xf;
	stepping = eax & 0xf;
	reserved = eax >> 12;

    CPUinfos.family = family;
    CPUinfos.model = model;
}

void DetectCPUName()
{
    //Detect cpu name string
    //Code from: https://github.com/pdoane/osdev/blob/master/cpu/detect.c
    struct new_cpud_id
    {
        //A different cpuid function
        static inline void new_cpuid(uint_32 reg, uint_32 *eax, uint_32 *ebx, uint_32 *ecx, uint_32 *edx)
        {
            __asm__ volatile("cpuid"
                : "=a" (*eax), "=b" (*ebx), "=c" (*ecx), "=d" (*edx)
                : "0" (reg));
        }
    };

    new_cpud_id nc;
    string n;
    nc.new_cpuid(0x80000002, (uint_32 *)(n +  0), (uint_32 *)(n +  4), (uint_32 *)(n +  8), (uint_32 *)(n + 12));
    nc.new_cpuid(0x80000003, (uint_32 *)(n + 16), (uint_32 *)(n + 20), (uint_32 *)(n + 24), (uint_32 *)(n + 28));
    nc.new_cpuid(0x80000004, (uint_32 *)(n + 32), (uint_32 *)(n + 36), (uint_32 *)(n + 40), (uint_32 *)(n + 44));

    string p = n;
    while (*p == ' ')
    {
        ++p;
    }

    CPUinfos.name = p;
}

void DetectCPU()
{
    DetectCPUFamilyAndModel();
    DetectCPUName();

	unsigned long ebx, unused;
	cpuid(0, unused, ebx, unused, unused);

	switch(ebx)
    {
        case INTEL_VENDOR_ID: 
            CPUinfos.vendor_id = INTEL_VENDOR_ID;
            DoIntel();
        break;
        case AMD_VENDOR_ID:
            CPUinfos.vendor_id = AMD_VENDOR_ID;
            DoAmd();
        break;
	}

    CPUinfos.isMSR = msr.CheckMSR();
}

void DoAmd()
{
    //TODO: AMD Support
}

void DoIntel()
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