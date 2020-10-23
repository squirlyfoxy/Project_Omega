#include "./include/string.h"

char integerToStringOutput[128];
char hexToStringOutput[128];
char floatToStringOutput[128];

bool isdigit(char c) {
  return c >= '0' && c <= '9';
}

//Convert string to int
int atoi(string str)
{
    int value = 0;
    while(isdigit(*str))
    {
        value *= 10;
        value += (*str)-'0';
        str++;
    }

    return value;
}

//Convert float to string
const char* FloatToString(float val, uint_8 decimalPlaces = 2)
{
    char* intPtr = (char*)(itoa((int)(val)));
    char* flaotPtr = floatToStringOutput;

    if(val < 0)
        val *= -1;

    while(*intPtr != 0)
    {
        *flaotPtr = *intPtr;
        intPtr++;
        flaotPtr++;
    }
    *flaotPtr = '.';
    flaotPtr++;

    float newValue = val - (int)(val);

    for(uint_8 i = 0; i < decimalPlaces; i++)
    {
        newValue *= 10;
        *flaotPtr = (int)(newValue + 48);
        newValue -= (int)(newValue);
        flaotPtr++;
    }

    *flaotPtr = 0;

    return floatToStringOutput;
}

uint_32 strlen(string str)
{
    uint_32 c = 0;

    while (*str != '\0')
    {
        c++;
        str++;
    }
    
    return c;
}