#include<stdio.h>
#include<stdlib.h>
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
#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target); // Correct declaration

int main()
{
    int nums[] = {1, 3, 5, 6};
    int target = 2;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int index = searchInsert(nums, numsSize, target); // Now valid!
    printf("%d\n", index); // Output: 1

    return 0;
}

int searchInsert(int* nums, int numsSize, int target)
{
    int low = 0, high = numsSize - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
            return mid;

        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low; // Correct insertion index if not found
}