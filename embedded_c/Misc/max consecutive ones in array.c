#include <stdio.h>

int findMaxConOnes(int arr[], int size)
{
    int maxCnt = 0;
    int curCnt = 0;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == 1)
        {
            curCnt++;
            if(curCnt > maxCnt)
            {
                maxCnt = curCnt;
            }
        }
        else
        {
            curCnt = 0;
        }
    }
    return maxCnt;
}


int main()
{
    int arr[] = {1, 1, 0, 1, 1, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = findMaxConOnes(arr, size);
    printf("Maximum consecutive ones: %d\n", result);
    return 0;
}