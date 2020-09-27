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