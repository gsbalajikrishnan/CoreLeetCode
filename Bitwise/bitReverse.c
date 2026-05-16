#include<stdio.h>
#include<stdint.h>
uint32_t reverseBits(uint32_t n);
void printBits(uint32_t bits);
int main()
{
    uint32_t value = 10;
    uint32_t retBits = reverseBits(value);
    printBits(retBits);
    return 0;
}
uint32_t reverseBits(uint32_t n) {
    uint32_t rev_bits = 0;
    uint32_t i=0;
        for(i=0;i<32;i++)
        {
            rev_bits <<= 1;
            rev_bits|=(n&1);
            // rev = rev<<1;
            // if((n&1)==1)
            // {
            //     rev=rev^1;
            // }
            n=n>>1;
        }
    return rev_bits;
}
void printBits(uint32_t bits)
{
    int i=0;
    for(i=31;i>=0;i--)
    {
        printf("%d",((bits>>i)&1));
    }
}
