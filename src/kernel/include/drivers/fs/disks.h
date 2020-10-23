#pragma once

#ifndef _DISKS_H
#define _DISKS_H

#include "../../typedef.h"
#include "../cmos.h"
#include "../../kprint.h"
#include "../../string.h"

//Libs
#include <omath.h>

#define MAX_MAPPED_DISKS 2

#define FLOPPY_NOTPRESENT_CODE   0x00
#define FLOPPY_360KB525_CODE     0x10
#define FLOPPY_1d20MB525_CODE    0x20
#define FLOPPY_720KB350_CODE     0x30
#define FLOPPY_1d44MB350_CODE    0x40
#define FLOPPY_2d88MB350_CODE    0x50

// Disk map (Array)
// 64bit for disk |type,size(byte),num|
extern uint_64 dskMap[MAX_MAPPED_DISKS];

//Create a disk map
void CheckDisks();

#endif