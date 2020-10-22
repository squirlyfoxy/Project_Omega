#include "../../include/drivers/fs/disks.h"

uint_64 dskMap[MAX_MAPPED_DISKS];

void CheckDisks()
{
    //For now map only floppys from CMOS
    unsigned char cmosOut = ReadCMOS(0x10);

    //Starts with converting char to uint_8
    uint_8 outInt = (uint_8)(cmosOut);

    //Converting this to 4bit int
    uint_8 x = SplitByte(outInt, 0);
    uint_8 y = SplitByte(outInt, 1);

    //dN = Disk Number
    //fC = Floppy Code

    //FLOPPY0
    if(x == FLOPPY_NOTPRESENT_CODE)
    {            //|dN(2),fC(2)| (For Now)
        dskMap[0] = 0000;
    } else if(x == FLOPPY_360KB525_CODE)
    {            //|dN(2),fC(2)|
         dskMap[0] = 0010;
    } else if(x == FLOPPY_1d20MB525_CODE)
    {            //|dN(2),fC(2)|
         dskMap[0] = 0020;
    } else if(x == FLOPPY_720KB350_CODE)
    {            //|dN(2),fC(2)|
         dskMap[0] = 0030;
    } else if(x == FLOPPY_1d44MB350_CODE)
    {            //|dN(2),fC(2)|
         dskMap[0] = 0040;
    } else if(x == FLOPPY_2d88MB350_CODE)
    {            //|dN(2),fC(2)|
         dskMap[0] = 0050;
    } else
    {
        //Non dovremmo mai entrare qui
    }

    //FLOPPY1
    if(y == FLOPPY_NOTPRESENT_CODE)
    {            //|dN(2),fC(2)| (For Now)
        dskMap[1] = 0100;
    } else if(y == FLOPPY_360KB525_CODE)
    {            //|dN(2),fC(2)|
         dskMap[1] = 0110;
    } else if(y == FLOPPY_1d20MB525_CODE)
    {            //|dN(2),fC(2)|
         dskMap[1] = 0120;
    } else if(y == FLOPPY_720KB350_CODE)
    {            //|dN(2),fC(2)|
         dskMap[1] = 0130;
    } else if(y == FLOPPY_1d44MB350_CODE)
    {            //|dN(2),fC(2)|
         dskMap[1] = 0140;
    } else if(y == FLOPPY_2d88MB350_CODE)
    {            //|dN(2),fC(2)|
         dskMap[1] = 0150;
    } else
    {
        //Non dovremmo mai entrare qui
    }
}