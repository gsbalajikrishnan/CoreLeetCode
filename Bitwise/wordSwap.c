#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
int main() {
    uint64_t value = 0x8975699998663391;
    uint64_t word1, word2;
    printf("Size %d\n",sizeof(uint64_t));
    printf("Value at 0x%016" PRIx64"\n",value);
    
    word1 = value<<32 & 0xFFFFFFFF00000000;
    printf("Value at 0x%016" PRIx64"\n",word1);
    
    word2 = value>>32 & 0xFFFFFFFF; 

    value = word1 | word2;
    printf("Value at 0x%016" PRIx64"\n",value);
    return 0;
}