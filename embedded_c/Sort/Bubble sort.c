#include <stdio.h>

void bubbleSort(int arr[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        int swapped = 0;
        for(int j = 0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            swapped = 1;
        }
        if(!swapped)
        {
            break;
        }
    }
}

// Helper function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Example usage
int main() {
    int data[] = {5, 1, 4, 2, 8};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Original array:\n");
    printArray(data, n);

    bubbleSort(data, n);

    printf("Sorted array:\n");
    printArray(data, n);

    return 0;
}