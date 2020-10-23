#include "../../include/drivers/fs/disks.h"

uint_64 dskMap[MAX_MAPPED_DISKS];

void CheckDisks()
{
     //dskMap set all to 1
     for(int i = 0; i < MAX_MAPPED_DISKS; i++)
          dskMap[i] = 0001;

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
          dskMap[0] = 0;
     } else if(x == FLOPPY_360KB525_CODE)
     {            //|dN(2),fC(2)|
          dskMap[0] = 10;
     } else if(x == FLOPPY_1d20MB525_CODE)
     {            //|dN(2),fC(2)|
          dskMap[0] = 20;
     } else if(x == FLOPPY_720KB350_CODE)
     {            //|dN(2),fC(2)|
          dskMap[0] = 30;
     } else if(x == FLOPPY_1d44MB350_CODE)
     {            //|dN(2),fC(2)|
          dskMap[0] = 40;
     } else if(x == FLOPPY_2d88MB350_CODE)
     {            //|dN(2),fC(2)|
          dskMap[0] = 50;
     }

     //FLOPPY1
     if(y == FLOPPY_NOTPRESENT_CODE)
     {            //|dN(2),fC(2)| (For Now)
          dskMap[1] = 100;
     } else if(y == FLOPPY_360KB525_CODE)
     {            //|dN(2),fC(2)|
          dskMap[1] = 110;
     } else if(y == FLOPPY_1d20MB525_CODE)
     {            //|dN(2),fC(2)|
          dskMap[1] = 120;
     } else if(y == FLOPPY_720KB350_CODE)
     {            //|dN(2),fC(2)|
          dskMap[1] = 130;
     } else if(y == FLOPPY_1d44MB350_CODE)
     {            //|dN(2),fC(2)|
          dskMap[1] = 0140;
     } else if(y == FLOPPY_2d88MB350_CODE)
     {            //|dN(2),fC(2)|
          dskMap[1] = 150;
     }

     for(int i = 0; i < MAX_MAPPED_DISKS; i++)
     {
          if(dskMap[i] != 0001)
          {
               //Check if it's a floppy
               if(i < 2)
               {
                    if(dskMap[i] == (uint_64)i * 100 + atoi(HexToString(FLOPPY_360KB525_CODE)))
                    {
                         printf("At index "); printf(itoa(i)); printf(" there is a 5.25inchs 360kb floppy"); printf("\n\r");
                    }
                    else if(dskMap[i] == (uint_64)i * 100 + atoi(HexToString(FLOPPY_1d20MB525_CODE)))
                    {
                         printf("At index "); printf(itoa(i)); printf(" there is a 5.25inchs 1.20mb floppy"); printf("\n\r");
                    }
                    else if(dskMap[i] == (uint_64)i * 100 + atoi(HexToString(FLOPPY_720KB350_CODE)))
                    {
                         printf("At index "); printf(itoa(i)); printf(" there is a 3.50inchs 720kb floppy"); printf("\n\r");
                    }
                    else if(dskMap[i] == (uint_64)i * 100 + atoi(HexToString(FLOPPY_1d44MB350_CODE)))
                    {
                         printf("At index "); printf(itoa(i)); printf(" there is a 3.50inchs 1.44mb floppy"); printf("\n\r");
                    }
                    else if(dskMap[i] == (uint_64)i * 100 + atoi(HexToString(FLOPPY_2d88MB350_CODE)))
                    {
                         printf("At index "); printf(itoa(i)); printf(" there is a 3.50inchs 2.88mb floppy"); printf("\n\r");
                    }
               }
          }
     }
}