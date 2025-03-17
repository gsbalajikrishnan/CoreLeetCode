/*
8-bit integer
Number-> 10
Binary-> 00001010 

Swap the 3rd bit & 4th bit
 */
#include<stdio.h>
#include<stdint.h>
int main()
{
    uint8_t num = 10; //0000 1010
    // Extract the 3rd bit position
    uint8_t bit3 = ((num >> 3) & 1);
    uint8_t bit4 = ((num >> 4) & 1);
    // Clear the bit 
    num = num & ~(1<<3);
    num = num & ~(1<<4);
    // Set the bit
    num = (num | bit3<<4);
    num = (num | bit4<<3);

    for(uint8_t i=8;i>0;i--)
    {
        printf("%d", (num & 1<<i)?1:0);
    }
}