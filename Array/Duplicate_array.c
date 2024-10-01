// Online C compiler to run C program online
#include <stdio.h>
int removeDuplicates(int* nums, int numsSize);
int main()
{
    int a[]={0,0,1,1,1,2,2,3,3,4};
    int i;
    int num_size=sizeof(a)/sizeof(a[0]);
    int size = removeDuplicates(&a[0],num_size);
    for(i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
int removeDuplicates(int* nums, int numsSize) 
{
    int i,j,k;
    for(i=0;i<numsSize;i++)
    {
        for(j=i+1;j<numsSize;j++)
        {
            if(nums[i]==nums[j])
            {
                for(k=j;k<numsSize-1;k++)
                {
                    nums[k]=nums[k+1];
                }
                numsSize--;
                j--;
            }
        }
    }

    return numsSize;
}