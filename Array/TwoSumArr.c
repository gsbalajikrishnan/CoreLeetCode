/* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
 */

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
int*  twoSum(int* nums, int numsSize, int target, int* returnSize);

int main()
{
    int nums[MAX_SIZE];
    //int numsSize = sizeof(nums)/sizeof(nums[0]);
    int target;
    int returnSize;
    int *index;
    printf("Get the array element:");
    for (size_t i = 0; i < MAX_SIZE;i++)
    {
        scanf("%d\n",&nums[i]);
    }
    scanf("%d",&target);
    

    index = twoSum(nums,MAX_SIZE,target,&returnSize);
    if(index!=NULL && returnSize==2)
    {
        printf("[%d,%d]",index[0],index[1]);
        free(index);
    }
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* indices = (int*)malloc(numsSize * sizeof(int));
    int i, j;
    if (indices == NULL) {
        return NULL;
    }
    *returnSize = 0;
    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                indices[0] = i;
                indices[1] = j;
                *returnSize = 2;
            }
        }
    }
    return indices;
}
