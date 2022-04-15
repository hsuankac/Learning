//
//  main.cpp
//  matrix
//
//  Created by Kai Chang on 3/27/22.
//
// Create a lower triangular matrix, row major representation
// for column major representation, use [n * (j-1) - (j-2) * (j-1) / 2 + i-j]
#include <iostream>

class LowerTri
{
private:
    int *A;
    int n;
public:
    LowerTri()
    {
        n = 2;
        A = new int[2 * (2+1) /2];
    }
    LowerTri(int n)
    {
        this->n = n;
        A = new int [n * (n+1) / 2];
    }
    ~LowerTri()
    {
        delete [] A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};

void LowerTri::Set(int i, int j, int x)
{
    if(i>=j)
        A[i * (i-1) /2 + j-1] = x;
}

int LowerTri::Get(int i, int j)
{
    if(i>=j)
        return A[i * (i-1) /2 + j-1];
    return 0;
}

void LowerTri::Display()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i>=j)
                std::cout << A[i * (i-1) /2 + j-1] << " ";
            else
                std::cout << "0 ";
        }
        std::cout << "\n";
    }
}

int main(int argc, const char * argv[]) {
    int d;
    std::cout << "Enter the dimension: ";
    std::cin >> d;
    LowerTri lm(d);
    
    int x;
    std::cout << "Enter all elements: " << std::endl;
    for(int i=1; i<=d; i++)
    {
        for(int j=1; j<=d; j++)
        {
            std::cin >> x;
            lm.Set(i, j, x);
        }
    }
    
    std::cout << "\n\n";
    lm.Display();
    
    return 0;
}

