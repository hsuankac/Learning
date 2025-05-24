#include <stdio.h>

int missingNumber(int* nums, int numsize)
{
    int x1 = 0;
    int x2 = 0;
    for(int i = 0; i < numsize; i++)
    {
        x1 ^= nums[i];
    }
    for(int i = 0; i <= numsize; i++)
    {
        x2 ^= i;
    }
    return x1 ^ x2;
}

int main()
{
    int nums1[] = {3, 0 ,1};
    int nums2[] = {0, 1};
    int nums3[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};

    int result1 = missingNumber(nums1, sizeof(nums1) / sizeof(nums1[0]));
    int result2 = missingNumber(nums2, sizeof(nums2) / sizeof(nums2[0]));
    int result3 = missingNumber(nums3, sizeof(nums3) / sizeof(nums3[0]));

    printf("Missing number in nums1: %d\n", result1);
    printf("Missing number in nums2: %d\n", result2);
    printf("Missing number in nums3: %d\n", result3);
    return 0;
}