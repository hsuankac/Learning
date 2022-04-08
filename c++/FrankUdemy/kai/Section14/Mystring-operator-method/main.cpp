#include <iostream>
#include "Mystring.h"
using namespace std;

int main() {
    cout << boolalpha << endl;
    Mystring larry{"Larry"};
    Mystring moe{"Moe"};
    
    Mystring stooge = larry;
    larry.display();
    moe.display();
    
    cout << (larry == moe) << endl;     //false
    cout << (larry == stooge) << endl;   // true
    
    larry.display();
    Mystring larry2 = -larry;
    larry2.display();
    
    Mystring stooges = larry + " Moe";
    return 0;
}