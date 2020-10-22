#include "../../include/drivers/fs/disks.h"

uint_64 dskMap[MAX_MAPPED_DISKS];

void CheckDisks()
{
    /*
    //For now only floppys from CMOS
    unsigned char cmosOut = ReadCMOS(0x10);

    //Starts with converting char to uint_8
    uint_8 outInt = (uint_8)(cmosOut);

    //Converting this to binary
    uint_8 x = SplitByte(outInt, 0);
    uint_8 y = SplitByte(outInt, 1);
    */
}