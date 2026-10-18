#include<stdio.h>
int main() {
    int a[2] = {1, 2};
    int *ptr = a;
    ptr = ptr + sizeof(int); // 20 bytes if system is 32 bit and 40 bytes if system is 64 bit
    
    printf("%d\n", *ptr);
    return 0;
}