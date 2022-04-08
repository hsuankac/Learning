// Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

struct Array
{
	int *a;
	int size;
	int length;
};

void swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void Display(struct Array arr)
{
	int i;
	printf("\nElements are\n");
	for (i = 0; i < arr.length; i++)
		printf("%d ", arr.a[i]);
}

void Append(struct Array* arr, int x)
{
	if (arr->length < arr->size)
		arr->a[arr->length++] = x;
}

void Insert(struct Array* arr, int index, int x)
{
	int i;
	if (index >= 0 && index <= arr->length)
	{
		for (i = arr->length; i > index; i--)
			arr->a[i] = arr->a[i - 1];
		arr->a[index] = x;
		arr->length++;
	}
}

int Delete(struct Array* arr, int index)
{
	int x = 0;
	if (index >= 0 && index < arr->length)
	{
		x = arr->a[index];
		for (int i = index; i < arr->length - 1; i++)
		{
			arr->a[i] = arr->a[i + 1];
		}
		arr->length--;
		return x;
	}
	return 0;
}

int LinearSearch(struct Array* arr, int key)
{
	int i;
	for (i = 0; i < arr->length; i++)
	{
		if (key == arr->a[i])
		{
			swap(&arr->a[i], &arr->a[0]);
			return i;
		}
	}
	return -1;
}

int BinarySearch(struct Array arr, int key)
{
	int l, mid, h;
	l = 0;
	h = arr.length - 1;
	while (l <= h)
	{
		mid = (l + h) / 2;
		if (key == arr.a[mid])
			return mid;
		else if (key < arr.a[mid])
			h = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

int RBinSearch(int a[], int l, int h, int key)
{
	int mid;
	if (l <= h)
	{
		mid = (l + h) / 2;
		if (key == a[mid])
			return mid;
		else if (key < a[mid])
			return RBinSearch(a, l, mid - 1, key);
		else
			return RBinSearch(a, mid + 1, h, key);
	}
	return -1;
}

int Get(struct Array arr, int index)
{
	if (index >= 0 && index < arr.length)
	{
		return arr.a[index];
	}
	return -1;
}

int Set(struct Array *arr, int index, int x)
{
	if (index >= 0 && index < arr -> length)
	{
		arr->a[index] = x;
	}
	return -1;
}

int Max(struct Array arr)
{
	int max = arr.a[0];
	int i;
	for (i = 0; i < arr.length; i++)
	{
		if (arr.a[i] > max)
			max = arr.a[i];
	}
	return max;
}

int Min(struct Array arr)
{
	int min = arr.a[0];
	int i;
	for (i = 0; i < arr.length; i++)
	{
		if (arr.a[i] < min)
			min = arr.a[i];
	}
	return min;
}

int Sum(struct Array arr)
{
	int s = 0;
	int i;
	for (i = 0; i < arr.length; i++)
	{
		s += arr.a[i];
	}
	return s;
}

float avg(struct Array arr)
{
	return (float)Sum(arr) / arr.length;
}

void Reverse(struct Array* arr)
{
	int* B;
	int i, j;
	B = (int *)malloc(arr->length * sizeof(int));
	for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
	{
		B[j] = arr->a[i];
	}
	for (i = 0; i < arr->length; i++)
	{
		arr->a[i] = B[i];
	}
}

void Reverse2(struct Array* arr)
{
	int i, j;
	for (i = 0, j = arr->length - 1; i < j; i++, j--)
	{
		swap(&arr->a[i], &arr->a[j]);
	}
}

void Rearrange(struct Array* arr)
{
	int i, j;
	i = 0;
	j = arr->length - 1;
	while (i < j)
	{
		while (arr->a[i] < 0) 
		{
			i++;
		}
		while (arr->a[j] >= 0)
		{
			j--;
		}
		if (i < j)
		{
			swap(&arr->a[i], &arr->a[j]);
		}
	}
}

void InsertSort(struct Array* arr, int x)
{
	int i = arr->length - 1;
	if (arr->length == arr->size)
	{
		return;
	}
	while (i>=0 && arr->a[i] > x)
	{
		arr->a[i + 1] = arr->a[i];
		i--;
	}
	arr->a[i + 1] = x;
	arr->length++;
}

int IsSorted(struct Array arr)
{
	int i;
	for (i = 0; i < arr.length - 1; i++)
	{
		if (arr.a[i] > arr.a[i + 1])
			return 0;
	}
	return 1;
}

struct Array* Merge(struct Array* arr1, struct Array* arr2)
{
	int i, j, k;
	i = j = k = 0;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->a[i] < arr2->a[j])
			arr3->a[k++] = arr1->a[i++];
		else
			arr3->a[k++] = arr2->a[j++];
	}
	for (; i < arr1->length; i++)
		arr3->a[k++] = arr1->a[i];
	for (; j < arr1->length; j++)
		arr3->a[k++] = arr2->a[j];
	arr3->length = arr1->length + arr2->length;
	arr3->size = 10;
	return arr3;
}

struct Array* Union(struct Array* arr1, struct Array* arr2)
{
	int i, j, k;
	i = j = k = 0;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->a[i] < arr2->a[j])
			arr3->a[k++] = arr1->a[i++];
		else if (arr2->a[j] < arr1->a[i])
			arr3->a[k++] = arr2->a[j++];
		else
		{
			arr3->a[k++] = arr1->a[i++];
			j++;
		}
	}
	for (; i < arr1->length; i++)
		arr3->a[k++] = arr1->a[i];
	for (; j < arr1->length; j++)
		arr3->a[k++] = arr2->a[j];
	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

struct Array* Intersection(struct Array* arr1, struct Array* arr2)
{
	int i, j, k;
	i = j = k = 0;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->a[i] < arr2->a[j])
			i++;
		else if (arr2->a[j] < arr1->a[i])
			j++;
		else
		{
			arr3->a[k++] = arr1->a[i++];
			j++;
		}
	}
	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

struct Array* Difference(struct Array* arr1, struct Array* arr2)
{
	int i, j, k;
	i = j = k = 0;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->a[i] < arr2->a[j])
			arr3->a[k++] = arr1->a[i++];
		else if (arr2->a[j] < arr1->a[i])
			j++;
		else
		{
			i++;
			j++;
		}
	}
	for (; i < arr1->length; i++)
		arr3->a[k++] = arr1->a[i];
	arr3->length = k;
	arr3->size = 10;
	return arr3;
}

int main()
{
	struct Array arr1;
	int ch;
	int x, index;

	printf("Enter Size of Array ");
	scanf_s("%d", &arr1.size);
	arr1.a = (int*)malloc(arr1.size * sizeof(int));
	arr1.length = 0;

	do
	{
		printf("\nMenu\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Search\n");
		printf("4. Sum\n");
		printf("5. Display\n");
		printf("6. Exit\n");

		printf("Enter your choice: ");
		scanf_s("%d", &ch);

		switch (ch)
		{
		case 1:
			printf("Enter an element and index ");
			scanf_s("%d%d", &x, &index);
			Insert(&arr1, index, x);
			break;
		case 2:
			printf("Enter index: ");
			scanf_s("%d", &index);
			x = Delete(&arr1, index);
			printf("Deleted element is %d\n", x);
			break;
		case 3:
			printf("Enter the element to search: ");
			scanf_s("%d", &x);
			index = LinearSearch(&arr1, x);
			printf("Element index %d", index);
			break;
		case 4:
			printf("Sum is %d\n", Sum(arr1));
			break;
		case 5:
			Display(arr1);
			break;
		}
	} while (ch < 6);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
