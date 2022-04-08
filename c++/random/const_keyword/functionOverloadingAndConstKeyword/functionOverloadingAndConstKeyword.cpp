#include<iostream>
using namespace std;

// C++ allows functions to be overloaded on the basis of const-ness of parameters only if the const parameter is a reference or a pointer
void fun(char* a)
{
	cout << "non-const fun() " << a;
}

void fun(const char* a)
{
	cout << "const fun() " << a;
}

int main()
{
	const char* ptr = "GeeksforGeeks";
	fun(ptr);
	return 0;
}


//// PROGRAM 1 (Fails in compilation)
//#include<iostream>
//using namespace std;
//
//void fun(const int i)
//{
//	cout << "fun(const int) called ";
//}
//void fun(int i)
//{
//	cout << "fun(int ) called ";
//}
//int main()
//{
//	const int i = 10;
//	fun(i);
//	return 0;
//}