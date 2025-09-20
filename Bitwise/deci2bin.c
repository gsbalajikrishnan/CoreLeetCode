/*
    Print decimal to binary 
*/
#include<stdio.h>
#include<stdint.h>
int main()
{
    uint8_t value = 200;
    for(int i=7;i>=0;i--)
    {
        printf("%d ",(value>>i & 1));
    }
 
    return 0;
}