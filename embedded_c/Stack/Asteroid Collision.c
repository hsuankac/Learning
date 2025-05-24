// https://leetcode.com/problems/asteroid-collision/description/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize)
{
    int* stack = (int*)malloc(sizeof(int) * asteroidsSize);
    int top = -1;
    for(int i = 0; i < asteroidsSize; i++)
    {
        int current = asteroids[i];
        int alive = 1;
        while(alive && current < 0 && top >= 0 && stack[top] > 0)
        {
            if(stack[top] < -current)
            {
                top--;
            }
            else if(stack[top] == -current)
            {
                top--;
                alive = 0;
            }
            else
            {
                alive = 0;
            }
        }
        if(alive)
        {
            stack[++top] = current;
        }
    }
    *returnSize = top + 1;
    return stack;
}

int main() 
{
    int input[] = {5, 10, -5};
    int size = sizeof(input) / sizeof(input[0]);
    int returnSize;
    int* result = asteroidCollision(input, size, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}