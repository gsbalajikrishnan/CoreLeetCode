#include<stdio.h>
#include<stdint.h>
uint8_t reverseBits(uint8_t n);
void printBits(uint8_t bits);
int main()
{
    uint8_t value = 0x55;
    printBits(value);
    printf("\n--------------------------\n");
    uint8_t retBits = reverseBits(value);
    printBits(retBits);
    return 0;
}
uint8_t reverseBits(uint8_t n) {
    uint8_t rev = 0;
    uint8_t i=0;
        for(i=0;i<8;i++)
        {
            rev = rev<<1;
            if((n&1)==1)
            {
                rev=rev | 1;
            }
            n=n>>1;
        }
    return rev;
}
void printBits(uint8_t bits)
{
    int i=0;
    for(i=7;i>=0;i--)
    {
        printf("%d ",((bits>>i)&1)); // ((bits & (1<<i))?1:0)
        
    }
}
