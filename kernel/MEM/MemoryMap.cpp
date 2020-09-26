#pragma one
#include "../include/typedef.h"

struct MemoryMapEntry
{
    uint_64 BaseAddress;
    uint_64 RegionLenght;
    uint_32 RegionType;
    uint_32 ExtendedAttributes;
};

extern uint_8 MemoryRegionCount;
