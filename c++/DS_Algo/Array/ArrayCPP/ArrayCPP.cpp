#include <iostream>
#include <stdlib.h>

class Array
{
private:
	int* a;
	int size;
	int length;
	void swap(int* x, int* y)
	{
		int temp;
		temp = *x;
		*x = *y;
		*y = temp;
	}

public:
	Array()
	{
		size = 10;
		length = 0;
		a = new int[size];
	}
	Array(int sz)
	{
		size = sz;
		length = 0;
		a = new int[size];
	}
	~Array() 
	{
		delete[] a;
	}
	void Display();
	void Append(int x);
	void Insert(int index, int x);
	int Delete(int index);

	int LinearSearch(int key);
	int BinarySearch(int key);

	//int RBinSearch(int a[], int l, int h, int key);
	int Get(int index);
	int Set(int index, int x);
	int Max();
	int Min();
	int Sum();
	float avg();
	void Reverse();
	void Reverse2();
	void InsertSort(int x);
	int IsSorted();
	void Rearrange();

	Array* Merge(Array arr2);
	Array* Union(Array arr2);
	Array* Intersection(Array arr2);
	Array* Difference(Array arr2);

};

void Array::Display()
{
	int i;
	printf("\nElements are\n");
	for (i = 0; i < length; i++)
		printf("%d ", a[i]);
}

void Array::Append(int x)
{
	if (length < size)
		a[length++] = x;
}

void Array::Insert(int index, int x)
{
	int i;
	if (index >= 0 && index <= length)
	{
		for (i = length; i > index; i--)
			a[i] = a[i - 1];
		a[index] = x;
		length++;
	}
}

int Array::Delete(int index)
{
	int x = 0;
	if (index >= 0 && index < length)
	{
		x = a[index];
		for (int i = index; i < length - 1; i++)
		{
			a[i] = a[i + 1];
		}
		length--;
		return x;
	}
	return 0;
}

int Array::LinearSearch(int key)
{
	int i;
	for (i = 0; i < length; i++)
	{
		if (key == a[i])
		{
			swap(&a[i], &a[0]);
			return i;
		}
	}
	return -1;
}

int Array::BinarySearch(int key)
{
	int l, mid, h;
	l = 0;
	h = length - 1;
	while (l <= h)
	{
		mid = (l + h) / 2;
		if (key == a[mid])
			return mid;
		else if (key < a[mid])
			h = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

//int RBinSearch(int a[], int l, int h, int key)
//{
//	int mid;
//	if (l <= h)
//	{
//		mid = (l + h) / 2;
//		if (key == a[mid])
//			return mid;
//		else if (key < a[mid])
//			return RBinSearch(a, l, mid - 1, key);
//		else
//			return RBinSearch(a, mid + 1, h, key);
//	}
//	return -1;
//}

int Array::Get(int index)
{
	if (index >= 0 && index < length)
	{
		return a[index];
	}
	return -1;
}

int Array::Set(int index, int x)
{
	if (index >= 0 && index < length)
	{
		a[index] = x;
	}
	return -1;
}

int Array::Max()
{
	int max = a[0];
	int i;
	for (i = 0; i < length; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

int Array::Min()
{
	int min = a[0];
	int i;
	for (i = 0; i < length; i++)
	{
		if (a[i] < min)
			min = a[i];
	}
	return min;
}

int Array::Sum()
{
	int s = 0;
	int i;
	for (i = 0; i < length; i++)
	{
		s += a[i];
	}
	return s;
}

float Array::avg()
{
	return (float)Sum() / length;
}

void Array::Reverse()
{
	int* B;
	int i, j;
	B = new int[length];
	for (i = length - 1, j = 0; i >= 0; i--, j++)
	{
		B[j] = a[i];
	}
	for (i = 0; i < length; i++)
	{
		a[i] = B[i];
	}
}

void Array::Reverse2()
{
	int i, j;
	for (i = 0, j = length - 1; i < j; i++, j--)
	{
		swap(&a[i], &a[j]);
	}
}

void Array::Rearrange()
{
	int i, j;
	i = 0;
	j = length - 1;
	while (i < j)
	{
		while (a[i] < 0)
		{
			i++;
		}
		while (a[j] >= 0)
		{
			j--;
		}
		if (i < j)
		{
			swap(&a[i], &a[j]);
		}
	}
}

void Array::InsertSort(int x)
{
	int i = length - 1;
	if (length == size)
	{
		return;
	}
	while (i >= 0 && a[i] > x)
	{
		a[i + 1] = a[i];
		i--;
	}
	a[i + 1] = x;
	length++;
}

int Array::IsSorted()
{
	int i;
	for (i = 0; i < length - 1; i++)
	{
		if (a[i] > a[i + 1])
			return 0;
	}
	return 1;
}

Array* Array::Merge(Array arr2)
{
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = new Array(length + arr2.length);
	while (i < length && j < arr2.length)
	{
		if (a[i] < arr2.a[j])
			arr3->a[k++] = a[i++];
		else
			arr3->a[k++] = arr2.a[j++];
	}
	for (; i < length; i++)
		arr3->a[k++] = a[i];
	for (; j < length; j++)
		arr3->a[k++] = arr2.a[j];
	arr3->length = length + arr2.length;
	return arr3;
}

Array* Array::Union(struct Array arr2)
{
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = new Array(length + arr2.length);
	while (i < length && j < arr2.length)
	{
		if (a[i] < arr2.a[j])
			arr3->a[k++] = a[i++];
		else if (arr2.a[j] < a[i])
			arr3->a[k++] = arr2.a[j++];
		else
		{
			arr3->a[k++] = a[i++];
			j++;
		}
	}
	for (; i < length; i++)
		arr3->a[k++] = a[i];
	for (; j < length; j++)
		arr3->a[k++] = arr2.a[j];
	arr3->length = k;
	return arr3;
}

Array* Array::Intersection(Array arr2)
{
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = new Array(length + arr2.length);
	while (i < length && j < arr2.length)
	{
		if (a[i] < arr2.a[j])
			i++;
		else if (arr2.a[j] < a[i])
			j++;
		else
		{
			arr3->a[k++] = a[i++];
			j++;
		}
	}
	arr3->length = k;
	return arr3;
}

Array* Array::Difference(Array arr2)
{
	int i=0, j=0, k=0;
	Array* arr3 = new Array(length + arr2.length);
	while (i < length && j < arr2.length)
	{
		if (a[i] < arr2.a[j])
			arr3->a[k++] = a[i++];
		else if (arr2.a[j] < a[i])
			j++;
		else
		{
			i++;
			j++;
		}
	}
	for (; i < length; i++)
		arr3->a[k++] = a[i];
	arr3->length = k;
	return arr3;
}

int main()
{
	Array* arr1;
	int ch, sz;
	int x, index;

	std::cout << "Enter Size of Array ";
	std::cin >> sz;
	arr1 = new Array(sz);

	do
	{
		std::cout << "\nMenu\n";
		std::cout << "1. Insert\n";
		std::cout << "2. Delete\n";
		std::cout << "3. Search\n";
		std::cout << "4. Sum\n";
		std::cout << "5. Display\n";
		std::cout << "6. Exit\n";

		std::cout << "Enter your choice: ";
		std::cin >> ch;

		switch (ch)
		{
		case 1:
			std::cout << "Enter an element and index ";
			std::cin >> x >> index;
			arr1->Insert(index, x);
			break;
		case 2:
			std::cout << "Enter index: ";
			std::cin >> index;
			x = arr1->Delete(index);
			std::cout << "Deleted element is" << x << std::endl;
			break;
		case 3:
			std::cout << "Enter the element to search: ";
			std::cin >> x;
			index = arr1->LinearSearch(x);
			std::cout << "Element index " << index << std::endl;
			break;
		case 4:
			std::cout << "Sum is: " << arr1->Sum() << std::endl;
			break;
		case 5:
			arr1->Display();
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
