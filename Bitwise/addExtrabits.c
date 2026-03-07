/* 
Case 1:
input: 0x5
output: 00001 1111

Case 2:
input: 0x7
output: 0111 1111

Case 3:
input: 0x8
output: 1111 1111
*/

#include<stdio.h>
#include<stdint.h>
int main()
{
    uint8_t value = 0x8;
    uint8_t data;
    data = value;
    for(uint8_t i=0;i<value;i++)
    {
        data = (data | (1<<i));
    }
    for(int8_t i=7;i>=0;i--)
    {
        printf("%u",((data>>i)&1));
    }
    //printf("0x%x",data);
    return 0;
}