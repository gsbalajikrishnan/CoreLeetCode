/*
Unset bits after specific bit 
 */
#include<stdio.h>
int main()
{
    int value = 0xFF; //1111 1111
    int bit = 5;
    value = value & ((1<<bit)-1);   
    printf("%x",value); //0000 0111
    return 0;
    
}