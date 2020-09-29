#ifndef _MSR_H
#define _MSR_H

#define CPUID_FLAG_MSR 1 << 5

//https://wiki.osdev.org/User:Lionel/MSR_Draft
#define IA32_P5_MC_ADDR 0x00000000
#define IA32_APIC_BASE 0x0000001B
#define IA32_FEATURE_CONTROL 0x0000003A //Read/Write
#define IA32_SAMPLE_AMD 0x000000FF
#define FCR 0x00001107
#define FCR2 0x00001108 //Read/Write
#define FCR3 0x00001109 //Write
#define EFER 0xC0000080 //Read/Write (For System Calls)

#endif