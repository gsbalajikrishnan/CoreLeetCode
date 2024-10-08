#include<stdio.h>
/*
Test case 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Test case 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Test case 3:
Input: nums = [1,3,5,6], target = 7
Output: 4


 */
int searchInsert(int* nums, int numsSize, int target);
int main()
{
    int nums[]={1,3,5,6},target=5,numsSize;
    int index;
    numsSize = sizeof(nums)/sizeof(nums[0]);
    index = searchInsert(nums, numsSize, target);
    printf("%d",index);

}

int searchInsert(int* nums, int numsSize, int target) 
{
    int low=0,high=numsSize-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]==target)
        {
            return mid;
        }
        else if(nums[mid]<target)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return low;
    
}

