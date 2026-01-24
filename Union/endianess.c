#include <stdio.h>
#include <stdint.h>

typedef union 
{
    uint32_t data;
    uint8_t value[4];
    /* data */
}Endianess;
int main() {
    Endianess endian;
    endian.data = 0x98917633;
    if (endian.value[0]==0x33)
    {
        printf("Little endianess");
        /* code */
    }
    else {
        printf("Big endianess");
    }
    return 0;
}
