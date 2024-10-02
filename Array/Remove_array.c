/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
int removeElement(int* nums, int numsSize, int val);
#include <stdio.h>
int main()
{
    int num[]={0,1,2,2,3,0,4,2};
    int val=2,ret,size;
    size = sizeof(num)/sizeof(num[0]);
    ret = removeElement(num,size,val);
    printf("\n%d",ret);

    return 0;
}
int removeElement(int* nums, int numsSize, int val) 
{
    int i,j,k;
    for(i=0;i<numsSize;i++)
    {
        for(j=i;j<numsSize;j++)
        {
            if(nums[j]==val)
            {
                for(k=j;k<numsSize;k++)
                {
                    nums[k] = nums[k+1];
                }
                numsSize--;
                j--;
            }
        }
    }
    return numsSize;       
}
