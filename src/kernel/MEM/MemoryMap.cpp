#pragma one
#include "../include/typedef.h"
#include "../kprint.cpp"
#include "../include/string.h"

struct MemoryMapEntry
{
    uint_64 BaseAddress;
    uint_64 RegionLenght;
    uint_32 RegionType;
    uint_32 ExtendedAttributes;
};

extern uint_8 MemoryRegionCount;
uint_8 UsableMemoryRegionsCount = 0;

MemoryMapEntry* UsableMemoryRegions[10];

//For debug only
void PrintMenoryMap(MemoryMapEntry* memoryMap, uint_16 position)
{
    SetCursorPosition(position);

    printf("Memory Base: "); printf(itoa(memoryMap->BaseAddress));
    SetCursorPosition(position + 80);

    printf("Region Lenght: "); printf(itoa(memoryMap->RegionLenght));
    SetCursorPosition(position + 160);

    printf("Memory Type: "); printf(itoa(memoryMap->RegionType));
    SetCursorPosition(position + 240);

    printf("Memory Attributes: "); printf(HexToString(memoryMap->ExtendedAttributes));
    SetCursorPosition(position + 400);
}

bool memoryRegionsGot = false;

MemoryMapEntry** GetUsableMemoryRegions()
{
    /*
    if(memoryRegionsGot)
        return UsableMemoryRegions; */

    uint_8 usableRegionIndex = 0;
    for(uint_8 i = 0; i < MemoryRegionCount; i++)
    {
        MemoryMapEntry* memMap = (MemoryMapEntry*)0x5000;
        memMap += i;

        if(memMap->RegionType == 1)
        {
            UsableMemoryRegions[usableRegionIndex] = memMap;
            usableRegionIndex++;
            UsableMemoryRegionsCount++;
        }

        UsableMemoryRegionsCount = usableRegionIndex;
    }

    memoryRegionsGot = true;
    return UsableMemoryRegions;
}