#include <stdio.h>
#include <stdint.h>

int is_aligned(uintptr_t address)
{
    return ((address & 0x7FFFF) == 0);
}

int main(void)
{
    uintptr_t address = 0x100000;

    if (is_aligned(address))
        printf("Address is 512 KB aligned\n");
    else
        printf("Address is NOT 512 KB aligned\n");

    return 0;
}