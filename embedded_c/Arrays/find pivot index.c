/*
* Finding the pivot index in an array means finding an index 
* such that the sum of the elements to the left is equal to the 
* sum of the elements to the right.
*/

#include <stdio.h>

int pivotIndex(int* nums, int size)
{
    int rightSum = 0;
    for(int i = 0; i < size; i++)
    {
        rightSum += nums[i];
    }
    int leftSum = 0;
    for(int i = 0; i < size; i++)
    {
        rightSum -= nums[i];
        if(leftSum == rightSum)
        {
            return i;
        }
        leftSum += nums[i];
    }
    return 0;
}


int main()
{
    int nums[] = {1, 7, 3, 6, 5, 6};
    int numsize = sizeof(nums) / sizeof(nums[0]);
    int result = pivotIndex(nums, numsize);
    printf("Pivot index is: %d\n", result);
    return 0;
}