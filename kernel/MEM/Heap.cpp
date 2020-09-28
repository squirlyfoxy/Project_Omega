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
        {
            if(currentMemorySegment->MemoryLenght != size)
            {
                MemorySegmentHeader* newSegmentHeader = (MemorySegmentHeader*)((uint_64)(currentMemorySegment + sizeof(MemorySegmentHeader) + size));

                newSegmentHeader->Free = true;
                newSegmentHeader->MemoryLenght = ((uint_64)currentMemorySegment->MemoryLenght) - (sizeof(MemorySegmentHeader) + size);
                newSegmentHeader->NextFreeSegment = currentMemorySegment->NextFreeSegment;
                newSegmentHeader->NextSegment = currentMemorySegment->NextSegment;
                newSegmentHeader->PreviusSegment = currentMemorySegment;
                newSegmentHeader->PreviusFreeSegment = currentMemorySegment->PreviusFreeSegment;

                currentMemorySegment->NextFreeSegment = newSegmentHeader;
                currentMemorySegment->NextSegment = newSegmentHeader;
            }

            if(currentMemorySegment == FirstFreeMemorySegment)
                FirstFreeMemorySegment = currentMemorySegment->NextFreeSegment;

            currentMemorySegment->Free = false;
            currentMemorySegment->MemoryLenght = size;

            if(currentMemorySegment->PreviusFreeSegment != 0)
                currentMemorySegment->PreviusFreeSegment->NextFreeSegment = currentMemorySegment->NextFreeSegment;

            if(currentMemorySegment->NextFreeSegment != 0)
                currentMemorySegment->NextFreeSegment->PreviusFreeSegment = currentMemorySegment->PreviusFreeSegment;

            return currentMemorySegment + 1;
        }

        if(currentMemorySegment->NextFreeSegment == 0)
        {
            return 0; //No free memory
        }

        currentMemorySegment = currentMemorySegment->NextFreeSegment;
    }

    return 0; //We should never get here
}