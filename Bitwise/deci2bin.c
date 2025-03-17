/*
    Print decimal to binary 
 */
#include<stdio.h>
#include<stdint.h>
int main()
{
    uint8_t value = 200;
    for(uint8_t i=8;i>0;i--)
    {
        printf("%d ",(value & (1<<i))?1:0);
    }
    
    return 0;

}