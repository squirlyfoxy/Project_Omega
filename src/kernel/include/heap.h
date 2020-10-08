#ifndef _HEAP_H
#define _HEAP_H

#include "typedef.h"
#include "../MEM/memory.cpp"

struct MemorySegmentHeader 
{
    uint_64 MemoryLength;
    MemorySegmentHeader* NextSegment;
    MemorySegmentHeader* NextFreeSegment;
    MemorySegmentHeader* PreviousSegment ;
    MemorySegmentHeader* PreviousFreeSegment ;
    bool Free;
};

void* malloc(uint_64 size);
void* realloc(void* address, uint_64 newSize);
void* calloc(uint_64 size);
void* calloc(uint_64 num, uint_64 size);
void CombineFreeSegments(MemorySegmentHeader* a, MemorySegmentHeader* b);
void free(void* address);

#endif