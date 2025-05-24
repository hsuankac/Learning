// https://leetcode.com/problems/daily-temperatures/description/
#include <stdio.h>
#include <stdlib.h>

int* dailyTemp(int* temperature, int tempSize, int* retSize)
{
    int* answer = (int*)calloc(tempSize, sizeof(int));
    int* stack = (int*)malloc(sizeof(int) * tempSize);
    int top = -1;
    for(int i = 0; i < tempSize; i++)
    {
        while(top >= 0 && temperature[i] > temperature[stack[top]])
        {
            int index = stack[top--];
            answer[index] = i - index;
        }

        stack[++top] = i;
    }
    free(stack);
    *retSize = tempSize;
    return answer;
}

int main()
{
    int temperature[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int tempSize = sizeof(temperature) / sizeof(temperature[0]);
    int retSize;
    int* result = dailyTemp(temperature, tempSize, &retSize);
    for(int i = 0; i < retSize; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}