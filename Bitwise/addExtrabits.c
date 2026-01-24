#include<stdio.h>
#include<stdint.h>
int main()
{
    uint32_t value = 0x5;
    uint32_t i, data;
    data = value;
    for(i=0;i<value;i++)
    {
        data = (data | (1<<i));
    }
    printf("0x%x",data);
    return 0;
}
