#pragma once

#ifndef _DISKS_H
#define _DISKS_H

#include "../../typedef.h"
#include "../cmos.h"

//Libs
#include <omath.h>

#define MAX_MAPPED_DISKS 2

#define FLOPPY_NOTPRESENT_CODE   00
#define FLOPPY_360KB525_CODE     10
#define FLOPPY_1d20MB525_CODE    20
#define FLOPPY_720KB350_CODE     30
#define FLOPPY_1d44MB350_CODE    40
#define FLOPPY_2d88MB350_CODE    50

// Disk map (Array)
// 64bit for disk |type,size(byte),num|
extern uint_64 dskMap[MAX_MAPPED_DISKS];

//Create a disk map
void CheckDisks();

#endif