#include<stdio.h>
#include<stdint.h>
int main() {
    uint32_t value = 0x98979692;
    printf("Before swap:0x%x\n",value);
    value = (((value<<24) & 0xFF000000) | ((value<<8) & 0x00FF0000) | ((value>>8) & 0x0000FF00) | ((value>>24)&0xFF));
    printf("After swap:0x%x",value);
}