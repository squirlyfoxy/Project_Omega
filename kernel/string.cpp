#pragma one

//Convert Hex to String
char hexToStringOutput[128];
template <typename T>
const char* HexToString(T value)
{
    T* valPtr = &value;
    uint_8* ptr;
    uint_8 tmp, size = (sizeof(T)) * 2 - 1, i;

    for (i = 0; i < size; i++)
    {
        ptr = ((uint_8*)valPtr + i);
        tmp = ((*ptr & 0xF0) >> 4);
        hexToStringOutput[size - (i * 2 + 1)] = tmp + (tmp > 9 ? 55 : 48);
        tmp = ((*ptr & 0x0F));
        hexToStringOutput[size - (i * 2)] = tmp + (tmp > 9 ? 55 : 48);
    }
    hexToStringOutput[size + 1] = 0;

    return hexToStringOutput;
}