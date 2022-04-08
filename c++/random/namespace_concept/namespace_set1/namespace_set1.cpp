// namespace_set1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
// In each scope, a name can only represent one entity. So, there cannot be two variables with the same name in the same scope. 
// Using namespaces, we can create two variables or member functions having the same name.

// Namespace declarations appear only at global scope.
// Namespace declarations can be nested within another namespace.
// Namespace declarations don’t have access specifiers. (Public or private)
// No need to give semicolon after the closing brace of definition of namespace.
// We can split the definition of namespace over several units.

// example 1:
//namespace first
//{
//    int val = 500;
//}
//
//int val = 100;
//
//int main()
//{
//    int val = 200;
//
//    std::cout << first::val << std::endl;
//    return 0;
//}

// example 2:
//namespace ns1
//{
//    int value() { return 5; }
//}
//namespace ns2
//{
//    const double x = 100;
//    double value() { return 2 * x; }
//}
//
//int main()
//{
//    // Access value function within ns1
//    cout << ns1::value() << '\n';
//
//    // Access value function within ns2
//    cout << ns2::value() << '\n';
//
//    // Access variable x directly
//    cout << ns2::x << '\n';
//
//    return 0;
//}

// A C++ program to demonstrate use of class
// in a namespace
//namespace ns
//{
//    // A Class in a namespace
//    class geek
//    {
//    public:
//        void display()
//        {
//            cout << "ns::geek::display()\n";
//        }
//    };
//}
//
//int main()
//{
//    // Creating Object of geek Class
//    ns::geek obj;
//
//    obj.display();
//
//    return 0;
//}

// A C++ program to demonstrate use of class
// in a namespace
//namespace ns
//{
//    // Only declaring class here
//    class geek;
//}
//
//// Defining class outside
//class ns::geek
//{
//public:
//    void display()
//    {
//        cout << "ns::geek::display()\n";
//    }
//};
//
//int main()
//{
//    //Creating Object of geek Class
//    ns::geek obj;
//    obj.display();
//    return 0;
//}


// A C++ code to demonstrate that we can define 
// methods outside namespace.

// Creating a namespace
namespace ns
{
    void display();
    class geek
    {
    public:
        void display();
    };
}

// Defining methods of namespace
void ns::geek::display()
{
    cout << "ns::geek::display()\n";
}
void ns::display()
{
    cout << "ns::display()\n";
}

// Driver code
int main()
{
    ns::geek obj;
    ns::display();
    obj.display();
    return 0;
}