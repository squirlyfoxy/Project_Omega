#pragma once

#ifndef _DISKS_H
#define _DISKS_H

#include "../../typedef.h"
#include "../cmos.h"

//Libs
#include <omath.h>

#define MAX_MAPPED_DISKS 2

// Disk map (Array)
// 64bit for disk |type,size(byte),num|
extern uint_64 dskMap[MAX_MAPPED_DISKS];

//Create a disk map
void CheckDisks();

#endif