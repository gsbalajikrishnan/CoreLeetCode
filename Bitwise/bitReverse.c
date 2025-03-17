#include<stdio.h>
#include<stdint.h>
uint32_t reverseBits(uint32_t n);
void printBits(uint32_t bits);
int main()
{
    uint32_t value = 0xFF;
    uint32_t retBits = reverseBits(value);
    printBits(retBits);
    return 0;
}
uint32_t reverseBits(uint32_t n) {
    uint32_t rev = 0;
    uint32_t i=0;
        for(i=0;i<32;i++)
        {
            rev = rev<<1;
            if((n&1)==1)
            {
                rev=rev^1;
            }
            n=n>>1;
        }
    return rev;
}
void printBits(uint32_t bits)
{
    int i=0;
    for(i=31;i>=0;i--)
    {
        printf("%d",((bits>>i)&1));
    }
}
