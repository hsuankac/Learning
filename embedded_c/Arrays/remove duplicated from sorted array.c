#include <stdio.h>

// remove in-place, use two pointers
int removeDuplicates(int* arr, int size)
{
    int j = 0;
    for(int i = 1; i < size; i++)
    {
        if(arr[i] != arr[j])
        {
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1;
}

// use an additional array
// int* removeDuplicates(int* arr, int size)
// {
//     int* newArr = (int*)malloc(sizeof(int) * size);
//     int newSize = 1;
//     newArr[0] = arr[0];
//     for(int i = 1; i < size; i++)
//     {
//         if(arr[i] != arr[i - 1])
//         {
//             newArr[newSize] = arr[i];
//             newSize++;
//         }
//     }
//     return newArr;
// }


int main()
{
    int arr[] = {1, 1, 2, 2, 3, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int newLength = removeDuplicates(arr, size);

    printf("Array after removing duplicates:\n");
    for (int i = 0; i < newLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nNew length: %d\n", newLength);

    return 0;
}