#include<stdio.h>
#include<string.h>
int main()
{
    int num[] = {1,2,3,4,5,6,7,8,9,10};
    int dest[10],i;
    int size = sizeof(num)/sizeof(num[0]);
    memcpy(dest, num, sizeof(num));
    for(i=0;i<size;i++)
    {
        printf("%d ",dest[i]);
    }
    return 0;
}