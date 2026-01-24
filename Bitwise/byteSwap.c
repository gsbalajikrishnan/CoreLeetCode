/*
 Byte swapping 
i/p -> 0x99998333;
o/p -> 0x33839899;
*/

#include<stdio.h>
#include<stdint.h>
int main() {
uint32_t value = 0x98998333;
uint32_t byte1,byte2,byte3,byte4;
byte1 = value<<24 & 0xFF000000;
byte2 = value<<8 & 0x00FF0000;
byte3 = value>>16 & 0x0000FF00;
byte4 = value>>16 & 0x000000FF;

value = (byte1) | (byte2) | (byte3) | (byte4);
printf("0x%x",value);
return 0;
}