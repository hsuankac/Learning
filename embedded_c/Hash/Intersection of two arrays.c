#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Hash T->O(n+m) S->O(RANGE)
#define OFFSET 10000  // Offset for negative indexing
#define RANGE 20001   // Covers values from -10000 to +10000

int* intersectWithDuplicates(int *arr1, int size1, int *arr2, int size2, int *resultSize) {
    *resultSize = 0;
    int *hash = calloc(RANGE, sizeof(int));  // Hash map: value → count
    if (!hash) return NULL;

    // Build frequency table from arr1
    for (int i = 0; i < size1; i++) {
        hash[arr1[i] + OFFSET]++;
    }

    // Scan arr2 and collect common elements, reducing count in hash
    int *result = malloc((size1 < size2 ? size1 : size2) * sizeof(int));
    if (!result) {
        free(hash);
        return NULL;
    }

    for (int i = 0; i < size2; i++) {
        int idx = arr2[i] + OFFSET;
        if (hash[idx] > 0) {
            result[(*resultSize)++] = arr2[i];
            hash[idx]--;
        }
    }

    free(hash);
    if (*resultSize == 0) {
        free(result);
        return NULL;
    }

    return result;
}

// qsort + scan T->O(nlogn + mlogm) + O(n + m)
// int compare(const void *a, const void *b) 
// {
//     return (*(int *)a - *(int *)b);
// }

// int* arrayIntersection(int *arr1, int size1, int *arr2, int size2, int *resultSize) {
//     *resultSize = 0;

//     qsort(arr1, size1, sizeof(int), compare);
//     qsort(arr2, size2, sizeof(int), compare);

//     int *result = malloc((size1 < size2 ? size1 : size2) * sizeof(int));
//     if (!result) return NULL;

//     int i = 0, j = 0;

//     while (i < size1 && j < size2) {
//         if (arr1[i] < arr2[j]) {
//             i++;
//         } else if (arr1[i] > arr2[j]) {
//             j++;
//         } else {
//             // Check to avoid adding duplicates
//             if (*resultSize == 0 || result[*resultSize - 1] != arr1[i]) {
//                 result[(*resultSize)++] = arr1[i];
//             }
//             i++;
//             j++;
//         }
//     }

//     if (*resultSize == 0) {
//         free(result);
//         return NULL;
//     }

//     return result;
// }

int main() {
    int arr1[] = {4, 2, 3, 5, 2, 1, -1};
    int arr2[] = {7, 4, 2, -1, 2, 9};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int resultSize = 0;
    int *intersection = hashIntersection(arr1, size1, arr2, size2, &resultSize);

    if (intersection) {
        printf("Intersection: ");
        for (int i = 0; i < resultSize; i++) {
            printf("%d ", intersection[i]);
        }
        printf("\n");
        free(intersection);
    } else {
        printf("No intersection found.\n");
    }

    return 0;
}