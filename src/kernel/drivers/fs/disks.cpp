#include "../../include/drivers/fs/disks.h"

DiskMap* disks;

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

     DiskMap* floppy0 = (DiskMap*)malloc(sizeof(DiskMap));
     floppy0->number = 0;
     floppy0->diskType = DisksTypes::floppy;

     //FLOPPY0
     if(x == FLOPPY_NOTPRESENT_CODE)
     {            
          floppy0->byteSize = 0;
     } else if(x == FLOPPY_360KB525_CODE)
     {            
          floppy0->byteSize = 360000;
     } else if(x == FLOPPY_1d20MB525_CODE)
     {            
          floppy0->byteSize = 1200000;
     } else if(x == FLOPPY_720KB350_CODE)
     {            
          floppy0->byteSize = 720000;
     } else if(x == FLOPPY_1d44MB350_CODE)
     {            
          floppy0->byteSize = 1440000;
     } else if(x == FLOPPY_2d88MB350_CODE)
     {            
          floppy0->byteSize = 2880000;
     } else { }

     //FLOPPY1
     DiskMap* floppy1 = (DiskMap*)malloc(sizeof(DiskMap));
     floppy1->number = 1;
     floppy1->diskType = DisksTypes::floppy;
     floppy1->nextDisk = NULL;

     if(y == FLOPPY_NOTPRESENT_CODE)
     {            
          floppy1->byteSize = 0;
     } else if(y == FLOPPY_360KB525_CODE)
     {            
          floppy1->byteSize = 360000;
     } else if(y == FLOPPY_1d20MB525_CODE)
     {            
          floppy1->byteSize = 1200000;
     } else if(y == FLOPPY_720KB350_CODE)
     {            
          floppy1->byteSize = 720000;
     } else if(y == FLOPPY_1d44MB350_CODE)
     {            
          floppy1->byteSize = 1440000;
     } else if(y == FLOPPY_2d88MB350_CODE)
     {            
          floppy1->byteSize = 2880000;
     } else { }
     
     floppy0->nextDisk = floppy1;
     disks = floppy0;

     //Print flopy0 informations
     printf("At index "); printf(itoa(disks->number)); printf(" there is a "); printf(FloatToString(disks->byteSize / 1024 / 1024, 2)); printf("mb floppy"); printf("\n\r");
}