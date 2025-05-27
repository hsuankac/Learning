#include <stdio.h>

// Function to perform insertion sort
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];        // Element to be inserted
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert the key in the correct position
        arr[j + 1] = key;
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
    int data[] = {9, 5, 1, 4, 3};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Original array:\n");
    printArray(data, n);

    insertionSort(data, n);

    printf("Sorted array:\n");
    printArray(data, n);

    return 0;
}
