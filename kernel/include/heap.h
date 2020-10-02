#ifndef _HEAP_H
#define _HEAP_H

#include "typedef.h"

struct MemorySegmentHeader 
{
    uint_64 MemoryLenght;
    MemorySegmentHeader* NextSegment;
    MemorySegmentHeader* NextFreeSegment;
    MemorySegmentHeader* PreviusSegment;
    MemorySegmentHeader* PreviusFreeSegment;
    bool Free;
};

#endif