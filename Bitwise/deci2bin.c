/*
    Print decimal to binary 
 */
#include<stdio.h>
#include<stdint.h>
int main()
{
    int8_t value = 20;
    for(int8_t i=7;i>=0;i--)
    {
        printf("%d",((value>>i)&1));
    }    
    return 0;
}