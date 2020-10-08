#pragma once

#ifndef _MEMORY_MAP_H
#define _MEMORY_MAP_H

#include "../../typedef.h"
#include "../../kprint.h"
#include "../../string.h"

struct MemoryMapEntry
{
    uint_64 BaseAddress;
    uint_64 RegionLenght;
    uint_32 RegionType;
    uint_32 ExtendedAttributes;
};

void PrintMenoryMap(MemoryMapEntry* memoryMap, uint_16 position);
MemoryMapEntry** GetUsableMemoryRegions();

#endif