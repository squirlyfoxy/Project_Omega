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

void CombineFreeSegments(MemorySegmentHeader* a, MemorySegmentHeader* b)
{
    if(a == 0 || b == 0) return;
    if(a < b)
    {
        a->MemoryLenght += b->MemoryLenght + sizeof(MemorySegmentHeader);
        a->NextSegment = b->NextSegment;
        a->NextFreeSegment = b->NextFreeSegment;
        b->NextSegment->PreviusSegment = a;
        b->NextSegment->PreviusFreeSegment = a;
        b->NextFreeSegment->PreviusFreeSegment = a;
    } else
    {
        b->MemoryLenght += a->MemoryLenght + sizeof(MemorySegmentHeader);
        a->NextSegment = a->NextSegment;
        b->NextFreeSegment = a->NextFreeSegment;
        a->NextSegment->PreviusSegment = b;
        a->NextSegment->PreviusFreeSegment = b;
        a->NextFreeSegment->PreviusFreeSegment = b;
    }
    
}

void free(void* address)
{
    MemorySegmentHeader* currentMemorySegment = ((MemorySegmentHeader*)address) - 1;
    currentMemorySegment->Free = true;

    if(currentMemorySegment < FirstFreeMemorySegment)
        FirstFreeMemorySegment = currentMemorySegment;

    if(currentMemorySegment->NextFreeSegment != 0)
    {
        if(currentMemorySegment->NextFreeSegment->PreviusFreeSegment < currentMemorySegment)
            currentMemorySegment->NextFreeSegment->PreviusFreeSegment = currentMemorySegment;
    }

    if(currentMemorySegment->PreviusFreeSegment != 0)
    {
        if(currentMemorySegment->PreviusFreeSegment->NextFreeSegment > currentMemorySegment)
            currentMemorySegment->PreviusFreeSegment->NextFreeSegment = currentMemorySegment;
    }

    if(currentMemorySegment->NextSegment != 0)
    {
        currentMemorySegment->NextSegment->PreviusSegment = currentMemorySegment;

        if(currentMemorySegment->NextSegment->Free)
            CombineFreeSegments(currentMemorySegment, currentMemorySegment->NextSegment);
    }

    if(currentMemorySegment->PreviusSegment != 0)
    {
        currentMemorySegment->PreviusSegment->NextSegment = currentMemorySegment;

        if(currentMemorySegment->PreviusSegment->Free)
            CombineFreeSegments(currentMemorySegment, currentMemorySegment->PreviusSegment);
    }
}