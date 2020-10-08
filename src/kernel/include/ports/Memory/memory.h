#pragma once

#ifndef _MEMORY_H
#define _MEMORY_H

#include "../../typedef.h"

void* memmove(void* dstptr, const void* srcptr, uint_64 size);
void memcpy(void* destination, void* source, uint_64 num);
void memset(void* start, uint_64 value, uint_64 num);


#endif
