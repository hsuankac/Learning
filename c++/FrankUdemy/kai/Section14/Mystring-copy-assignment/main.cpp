#include <iostream>
#include <vector>
#include "Mystring.h"

int main() {
    Mystring a{"Hello"};
    Mystring b;
    b = a;
    
    b = "This is the best";
    return 0;
}