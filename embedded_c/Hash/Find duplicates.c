#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE            100

// void findDuplicates(int arr[], int size)
// {
//     int* hashTable = (int*)malloc(sizeof(int) * MAX_SIZE);
//     if(!hashTable)
//     {
//         printf("Unable to allocate memory\n");
//         return;
//     }
//     printf("Duplicates elements are: \n");
//     int found = 0;
//     for(int i = 0; i < size; i++)
//     {
//         hashTable[arr[i]]++;
//         if(hashTable[arr[i]] == 2)
//         {
//             printf("%d ", arr[i]);
//             found = 1;
//         }
//     }
//     if (!found) 
//     {
//         printf("None");
//     }

//     printf("\n");
//     free(hashTable);
// }

// qsort + linear scan version to support negative numbers
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int* findDuplicates(int *arr, int size, int *dupCount) {
    *dupCount = 0;
    if (size < 2) return NULL;

    qsort(arr, size, sizeof(int), compare);

    int *duplicates = (int *)malloc(size * sizeof(int));  // Worst case: all duplicates
    if (!duplicates) return NULL;

    for (int i = 1; i < size; i++) {
        if (arr[i] == arr[i - 1]) {
            if (i == 1 || arr[i] != arr[i - 2]) {
                duplicates[*dupCount] = arr[i];
                (*dupCount)++;
            }
        }
    }

    if (*dupCount == 0) {
        free(duplicates);
        return NULL;
    }

    return duplicates;
}



int main() {
    // int arr[] = {4, 2, 7, 2, 4, 9, 1, 7, 3};
    // int size = sizeof(arr) / sizeof(arr[0]);

    // findDuplicates(arr, size);
    int arr[] = {-5, 2, -3, -5, 2, 4, 7, 4, -3};
    int size = sizeof(arr) / sizeof(arr[0]);

    int dupCount = 0;
    int *duplicates = findDuplicates(arr, size, &dupCount);

    if (duplicates) {
        printf("Duplicate elements are: ");
        for (int i = 0; i < dupCount; i++) {
            printf("%d ", duplicates[i]);
        }
        printf("\n");
        free(duplicates);
    } else {
        printf("No duplicates found.\n");
    }

    return 0;
}