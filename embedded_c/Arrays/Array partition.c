#include <stdio.h>

void partitionArray(int arr[], int size) {
    int left = 0, right = size - 1;

    while (left < right) {
        // Move left forward if it's already negative
        while (arr[left] < 0 && left < right)
            left++;

        // Move right backward if it's already positive
        while (arr[right] >= 0 && left < right)
            right--;

        // Swap if left is positive and right is negative
        if (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, -7, -5, 3, -1, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, size);

    partitionArray(arr, size);

    printf("Partitioned array:\n");
    printArray(arr, size);

    return 0;
}
