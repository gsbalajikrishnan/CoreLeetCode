#include<stdio.h>
int main()
{
    unsigned int num = 0x12345678;
    unsigned char *ptr = (unsigned char*)&num;
    printf("\nAddress:%p, Value:%x", ptr, *ptr);
    printf("\nAddress:%p, Value:%x", ptr+1, *(ptr+1));
    printf("\nAddress:%p, Value:%x", ptr+2, *(ptr+2));
    printf("\nAddress:%p, Value:%x", ptr+3, *(ptr+3));

    printf("\nModified byte order");

    int data = ((num<<24 & 0xFF000000) | (num<<8 & 0x00FF0000) | (num>>8 & 0x0000FF00) | (num>>24 & 0x000000FF));
    unsigned char *ptra = (unsigned char*)&data;
    printf("\nAddress:%p, Value:%x", ptra, *ptra);
    printf("\nAddress:%p, Value:%x", ptra+1, *(ptra+1));
    printf("\nAddress:%p, Value:%x", ptra+2, *(ptra+2));
    printf("\nAddress:%p, Value:%x", ptra+3, *(ptra+3));

    
}