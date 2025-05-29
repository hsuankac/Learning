#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct 
{
    int value;
    int diff;
} Element;

int compare(const void* a, const void* b)
{
    Element* e1 = (Element*)a;
    Element* e2 = (Element*)b;

    if(e1->diff == e2->diff)
    {
        return e1->value - e2->value;
    }
    return e1->diff - e2->diff;
}

void findKClosest(int arr[], int n, int x, int k) 
{
    Element* elements = (Element*)malloc(sizeof(Element) * n);

    // Calculate difference
    for(int i = 0; i < n; i++)
    {
        elements[i].value = arr[i];
        elements[i].diff = abs(arr[i] - x);
    }

    // Sort by difference
    qsort(elements, n, sizeof(Element), compare);

    // print first k elements
    printf("The %d closest elements to %d are:\n", k, x);
    for(int i = 0; i < k; i++)
    {
        printf("%d ", elements[i].value);
    }
    printf("\n");
    free(elements);
}


int main()
{
    int arr[] = {10, 2, 14, 4, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;
    int k = 3;

    findKClosest(arr, n, x, k);
    return 0;
}