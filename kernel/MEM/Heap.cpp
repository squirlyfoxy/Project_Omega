#pragma once

#include "../include/heap.h"

MemorySegmentHeader* FirstFreeMemorySegment;

void InitHeap(uint_64 heapAddress, uint_64 heapLenght)
{
    FirstFreeMemorySegment = (MemorySegmentHeader*)heapAddress;
    FirstFreeMemorySegment->MemoryLenght = heapLenght - sizeof(MemorySegmentHeader);
    FirstFreeMemorySegment->NextSegment = 0;
    FirstFreeMemorySegment->PreviusSegment = 0;
    FirstFreeMemorySegment->NextFreeSegment = 0;
    FirstFreeMemorySegment->PreviusFreeSegment = 0;
    FirstFreeMemorySegment->Free = true;
}

void* malloc(uint_64 size)
{
    uint_64 remainder = size % 8;
    size -= remainder;

    if(remainder != 0)
        size += 8;

    MemorySegmentHeader* currentMemorySegment = FirstFreeMemorySegment;

    while (true)
    {
        if(currentMemorySegment->MemoryLenght >= size)
            return currentMemorySegment + 1;
    }
    
}