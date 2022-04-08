// C++ program to show overloading and accessing from different namespaces

#include <iostream>
#include <string>

// Declare namespace test_space1
namespace test_space1 {
	const std::string const_prefix = "(test_space1::string)";

	// String class
	class string {
	private:
		std::string str = "";
		// Private default constructor
		string();
	public:
		// Public parameterized constructor
		string(const std::string& s)
			:str(const_prefix + s)
		{
		}

		// Get string function
		std::string get_str() const
		{
			return str;
		}
	};
}

// Declare namespace test_space2
namespace test_space2 {
	const std::string const_prefix = "(test_space2::string)";

	class string {
	private:
		std::string str = "";
		const std::string check_scope = "test_space2!";
		string();
	public:
		string(const std::string& s)
			:str(const_prefix + s)
		{

		}

		std::string get_str() const
		{
			return str;
		}

		std::string getScopestr() const
		{
			return check_scope;
		}
	};
}

// Declare namespace test_space3
namespace test_space3 {
	const std::string const_prefix = "(test_space3::string) Accessing from both namespace test_space3 & ";

	class string {
	private:
		std::string str = "";
		string();
	public:
		string(const test_space2::string& s)
			:str(const_prefix + s.getScopestr())
		{

		}

		std::string get_str() const
		{
			return str;
		}
	};
}

// Overload << operator for test_space1
std::ostream& operator<<(std::ostream& os, const test_space1::string& s1)
{
	os << s1.get_str();
	return os;
}

// Overload << operator for test_space2
std::ostream& operator<<(std::ostream& os, const test_space2::string& s2)
{
	os << s2.get_str();
	return os;
}

// Overload << operator for test_space3
std::ostream& operator<<(std::ostream& os, const test_space3::string& s3)
{
	os << s3.get_str();
	return os;
}

int main()
{
	// String str
	const std::string str("This is a standard string");
	std::cout << str << std::endl;

	const std::string sample1("This is a test_space1 namespace string");
	const test_space1::string s2(sample1);
	std::cout << s2 << std::endl;

	const std::string sample2("This is a test_space2 namespace string");
	const test_space2::string s3(sample2);
	std::cout << s3 << std::endl;

	const test_space3::string s4(s3);
	std::cout << s4 << std::endl;

}