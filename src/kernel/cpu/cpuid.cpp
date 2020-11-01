#include "../include/cpu/cpuid.h"

void DoAmd();
void DoIntel();
void CpuExtendedFunctions();

MSR msr;
cpu CPUinfos;

void DetectCPU()
{
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

    ActivateSSE(); //Scheck and activate SSE
    CPUinfos.isMSR = msr.CheckMSR();
}

void DoAmd()
{
    //AMD Support

    //Get Family and Model number
	unsigned long extended, eax, ebx, ecx, edx, unused;
    int family, model, stepping, reserved;
	cpuid(1, eax, unused, unused, unused);
	model = (eax >> 4) & 0xf;
	family = (eax >> 8) & 0xf;
    stepping = eax & 0xf;
	reserved = eax >> 12;

    CPUinfos.model = model;
    CPUinfos.family = family;
    CPUinfos.steeping = stepping;

    CpuExtendedFunctions();
}

void DoIntel()
{
    //Intel Support

    //Get Family and Model number
    unsigned long eax, ebx, unused;
	int model, family, type, brand, stepping, reserved;
	cpuid(1, eax, ebx, unused, unused);
	model = (eax >> 4) & 0xf;
	family = (eax >> 8) & 0xf;
    type = (eax >> 12) & 0x3;
	brand = ebx & 0xff;
	stepping = eax & 0xf;
	reserved = eax >> 14;

    CPUinfos.model = model;
    CPUinfos.family = family;
    CPUinfos.steeping = stepping;

    CpuExtendedFunctions();
}

void CpuExtendedFunctions()
{
    unsigned long extended, eax, ebx, ecx, edx, unused;

    cpuid(0x80000000, extended, unused, unused, unused);

    if(extended == 0) //No extended functions
    {
        return;
    }

    //Cpu Name:
	if(extended >= 0x80000004)
    {
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

//Get DL value
uint_8 GetDLValue()
{
    uint_8 val;

    //Assembly
    asm volatile("movb %%dl, %0" : "=r" (val));

    return val;
}

//Get DH value
uint_8 GetDHValue()
{
    uint_8 val;

    //Assembly
    asm volatile("movb %%dh, %0" : "=r" (val));

    return val;
}
