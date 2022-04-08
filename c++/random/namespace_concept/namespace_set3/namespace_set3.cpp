// C++ program to demonstrate accessing of variables
// in normal way, i.e., using "using" directive
#include <iostream>
using namespace std;

//namespace geek
//{
//    int rel = 300;
//}
//
//// use of ‘using’ directive
//using namespace geek;
//
//int main()
//{
//    // variable ‘rel’ accessed 
//    // without using scope resolution variable
//    cout << rel << "\n";        //prints 300
//
//    return 0;
//}

// In C++, namespaces can also be nested i.e., one namespace inside another. The resolution of namespace variables is hierarchical.

// Nested namespace
//namespace out
//{
//    int val = 5;
//    namespace in
//    {
//        int val2 = val;
//    }
//}
//
//// Driver code
//int main()
//{
//    cout << out::in::val2;   // prints 5
//    return 0;
//}

// In C++, you can use an alias name for your namespace name, for ease of use. Existing namespaces can be aliased with new names, with the following syntax:
// namespace new_name = current_name;

//namespace name1
//{
//    namespace name2
//    {
//        namespace name3
//        {
//            int var = 42;
//        }
//    }
//}
//
//// Aliasing 
//namespace alias = name1::name2::name3;
//
//int main()
//{
//    std::cout << alias::var << '\n';
//}

// An inline namespace is a namespace that uses the optional keyword inline in its original-namespace-definition.

// C++ program to demonstrate working of
// inline namespaces inside inline namespaces

//namespace ns1
//{
//    inline namespace ns2
//    {
//        inline namespace ns3
//        {
//            int var = 10;
//        }
//    }
//}
//
//int main()
//{
//    cout << ns1::var;
//    return 0;
//}
// 
// “Using” directive
// A using-directive that names the inline namespace is implicitly inserted in the enclosing namespace (similar to the implicit using-directive for the unnamed namespace)

namespace ns1
{
    namespace ns2
    {
        namespace ns3
        {
            int var = 10;
        }
        using namespace ns3;
    }

    using namespace ns2;
}

int main()
{
    cout << ns1::var;
    return 0;
}