#include <stdio.h>
#include <stdlib.h>

// First approach, find left and right max for each index, O(n^2) time and O(1) space
// int maxWater(int arr[], int n)
// {
//     int res = 0;
//     // for evey element of the array
//     for(int i = 1; i < n - 1; i++)
//     {
//         // find the maximum element on its left
//         int left = arr[i];
//         for(int j = 0; j < i; j++)
//         {
//             if(arr[j] > left)
//             {
//                 left = arr[j];
//             }
//         }

//         // find the maximum element on its right
//         int right = arr[i];
//         for(int j = i + 1; j < n; j++)
//         {
//             if(arr[j] > right)
//             {
//                 right = arr[j];
//             }
//         }

//         // update the maximum water
//         res += (left < right ? left : right) - arr[i];
//     }
//     return res;
// }

// Second approach, prefix and suffix max for each index - O(n) time and O(n) space
// int maxWater(int arr[], int n)
// {
//     // left[i] contains height of tallest bar to the left of 'i'th bar including itself
//     int left[n];
//     int right[n];
//     int res = 0;
//     // Fill left array
//     left[0] = arr[0];
//     for (int i = 1; i < n; i++)
//         left[i] = left[i - 1] > arr[i] ? left[i - 1] : arr[i];

//     // Fill right array
//     right[n - 1] = arr[n - 1];
//     for (int i = n - 2; i >= 0; i--)
//         right[i] = right[i + 1] > arr[i] ? right[i + 1] : arr[i];

//     // Calculate the accumulated water element by element
//     for (int i = 1; i < n - 1; i++) {
//         int minOf2 = left[i] < right[i] ? left[i] : right[i];
//             res += minOf2 - arr[i];
//     }

//     return res;
// }

// Third approach, two pointers ,O(n) time O(1) space
// int maxWater(int arr[], int n)
// {
//     if(n == 0) return 0;
//     int left = 0, right = n - 1;
//     int left_max = 0, right_max = 0;
//     int water = 0;
//     while(left < right)
//     {
//         if(arr[left] < arr[right])
//         {
//             if(arr[left] >= left_max)
//             {
//                 left_max = arr[left];
//             }
//             else
//             {
//                 water += left_max - arr[left];
//             }
//             left++;
//         }
//         else
//         {
//             if(arr[right] >= right_max)
//             {
//                 right_max = arr[right];
//             }
//             else
//             {
//                 water += right_max - arr[right];
//             }
//             right--;
//         }
//     }
//     return water;
// }

// fourth approach, using stack, O(n) time, O(n) space

struct stack
{
    int* array;
    int top;
    int capacity;
};

struct stack* createStack(int capacity)
{
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(sizeof(int) * capacity);
    return stack;
}

int isFull(struct stack* stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct stack* stack)
{
    return stack->top == -1;
}

void push(struct stack* stack, int item)
{
    if(isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(struct stack* stack)
{
    if(isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

int top(struct stack* stack)
{
    return stack->array[stack->top];
}

int maxWater(int* arr, int n)
{
    struct stack* st = createStack(n);
    int res = 0;

    for(int i = 0; i < n; i++)
    {
        // pop all items smaller than arr[i]
        while(!isEmpty(st) && arr[top(st)] < arr[i])
        {
            int pop_height = arr[pop(st)];
            if(isEmpty(st))
                break;
            // arr[i] is the next greater for the removed item
            // and new stack top is the previous greater 
            int distance = i - top(st) - 1;
            // Take the minimum of two heights (next and prev greater)
            int water = (arr[top(st)] < arr[i]) ? arr[top(st)] : arr[i];
            // Find the amount of water
            water -= pop_height;
            res += distance * water;
        }
        push(st, i);
    }
    free(st->array);
    free(st);
    return res;
}


int main()
{
    int arr[] = {2, 1, 5, 3, 1, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", maxWater(arr, n));
    return 0;
}