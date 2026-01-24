#include<stdio.h>
#include<stdint.h>
int main() {
uint8_t const data = 20;
uint8_t *ptr = (uint8_t*)&data;
*ptr = 28;
printf("%d",data);
return 0;

}