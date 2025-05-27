#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        // assume the current index is the minimum
        int minIndex = i;
        for(int j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // swap if a new minimum is found
        if(minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int data[] = {64, 25, 12, 22, 11};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Original array:\n");
    printArray(data, n);

    selectionSort(data, n);

    printf("Sorted array:\n");
    printArray(data, n);

    return 0;
}