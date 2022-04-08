// SumNaturalNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int sum(int n)
{
    if (n == 0)
        return 0;
    else
        return sum(n - 1) + n;
}

int Isum(int n)
{
    int s = 0;
    int i;
    for (i = 1; i <= n; i++)
    {
        s = s + i;
    }
    return s;
}

int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return fact(n - 1) * n;

}

int Ifact(int n)
{
    int f = 1;
    int i;
    for (i = 1; i <= n; i++) {
        f = f * i;
    }
    return f;
}

int main()
{
    std::cout << sum(5) << std::endl;
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
