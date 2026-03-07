#include<stdio.h>
#include<stdint.h>
int main() {
    uint16_t n=0x88;
    uint16_t count=0,i;
    // while(n!=0) {
    //     if(n & 1) {
    //         count++;
    //     }
    //     n=n>>1;
    // }
    for (i = 0; i <16; i++)
    {
        if(n & (1<<i)) {
            count++;
        } 
        /* code */
    }
    
    printf("%d",count);
    return 0;
}
