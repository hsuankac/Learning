// ArrayClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template<class T>
class Array 
{
private:
    T* A;
    int size;
    int length;
public:
    Array()
    {
        size = 10;
        A = new T[10];
        length = 0;
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new T[size];
    }
    ~Array()
    {
        delete[] A;
    }
    void Display();
    void Insert(int index, T x);
    T Delete(int index);
};

template<class T>
void Array<T>::Display()
{
    for (int i = 0; i < length; i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

template<class T>
void Array<T>::Insert(int index, T x)
{
    if (index >= 0 && index <= length)
    {
        for (int i = length - 1; i >= index; i--)
        {
            A[i + 1] = A[i];
        }
        A[index] = x;
        length++;
    }
}

template<class T>
T Array<T>::Delete(int index)
{
    int x = 0;
    if (index >= 0 && index < length)
    {
        x = A[index];
        for (int i = index; i < length - 1; i++) 
        {
            A[i] = A[i + 1];
        }
        length--;
    }
    return x;
}

int main()
{
    Array<char> arr(10);
    arr.Insert(0, 'a');
    arr.Insert(1, 'c');
    arr.Insert(2, 'd');
    arr.Display();
    std::cout << arr.Delete(0) << std::endl;
    arr.Display();
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
