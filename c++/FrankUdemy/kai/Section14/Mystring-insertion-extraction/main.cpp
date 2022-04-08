#include <iostream>
#include "Mystring.h"

using namespace std;

int main() {
    Mystring larry{"Larry"};
    Mystring moe{"Moe"};
    Mystring curly;
    
    cout << "Enter the third stooges name: ";
    cin >> curly;
    cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << std::endl; 
    
    return 0;
}