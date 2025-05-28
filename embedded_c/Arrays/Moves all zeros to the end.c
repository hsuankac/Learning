#include <stdio.h>

void moveZeroes(int arr[], int size) {
    int nonZeroIndex = 0;

    // First pass: move non-zero elements forward
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            arr[nonZeroIndex++] = arr[i];
        }
    }

    // Fill remaining positions with zeroes
    while (nonZeroIndex < size) {
        arr[nonZeroIndex++] = 0;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {0, 1, 0, 3, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, size);

    moveZeroes(arr, size);

    printf("After moving zeroes to the end:\n");
    printArray(arr, size);

    return 0;
}
