#include <iostream>
#include "Mystring.h"


int main() {
    Mystring larry{"Larry"};
//    larry.display();
//    
//    larry = -larry;
//    larry.display();
//    
    Mystring stooges = "Moe" + larry; 
    stooges.display();
    return 0;
}