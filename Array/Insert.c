#include<stdio.h>
#define MAX_SIZE 5
int main()
{
    int num[5] = {10,20,30,40,50};
    int i,pos=2;
    for(i=MAX_SIZE-1;i>=pos;i--)
    {
        num[i+1] = num[i];
    }
    num[pos]=25;
    for (i = 0; i < MAX_SIZE; i++)
    {
        printf("%d",num[i]);
    }
    
}