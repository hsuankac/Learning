#include "Mystring.h"
#include <cstring>
#include <iostream>

// overload constructor
Mystring::Mystring(const char *s)
    :str{nullptr}
{
    if(s == nullptr){
        str = new char [1];
        *str = '\0';
    } else {
        str = new char [std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

// destructor
Mystring::~Mystring()
{
    delete [] str;
}

// copy assignment
Mystring &Mystring::operator=(const Mystring &rhs)
{
    if (this == &rhs)
        return *this;
    delete [] this -> str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(this->str, rhs.str);
    return *this;
}

// move assignment
Mystring &Mystring::operator=(Mystring &&rhs)
{
    if(this == &rhs)
        return *this;
    delete [] this -> str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// copy constructor
Mystring::Mystring(const Mystring &source)
    :str{nullptr}
{
    str = new char [std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

// move constructor
Mystring::Mystring(Mystring &&source)
    :str(source.str)
{
    source.str = nullptr;
    std::cout << "Move constructor used" << std::endl;
}

void Mystring::display() const
{
    std::cout << str << ":" << get_length() << std::endl;
}

int Mystring::get_length() const
{
    return std::strlen(str);
}

const char *Mystring::get_str() const
{
    return str;
}

// equality
bool Mystring::operator==(const Mystring &rhs) const
{
    return (std::strcmp(str, rhs.str) == 0);
}

// not equal
bool Mystring::operator!=(const Mystring &rhs) const
{
    return !(std::strcmp(str, rhs.str) == 0);
}

// less than
bool Mystring::operator<(const Mystring &rhs) const
{
    return (std::strcmp(str, rhs.str) < 0);
}

// greater than
bool Mystring::operator>(const Mystring &rhs) const
{
    return (std::strcmp(str, rhs.str) > 0);
}

// make lowercase
Mystring Mystring::operator-() const
{
    char *buff = new char [std::strlen(this->str) + 1];
    std::strcpy(buff, str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

// concatenate
Mystring Mystring::operator+(const Mystring &rhs) const
{
    char *buff = new char [std::strlen(this->str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

// concat and assign
Mystring &Mystring::operator+=(const Mystring &rhs)
{
    *this = *this + rhs;
    return *this;
}

// repeat
Mystring Mystring::operator*(int n) const
{
    Mystring temp;
    for (int i=1; i<=n; i++)
        temp = temp + *this;
    return temp;
}

// repeat and assign
Mystring &Mystring::operator*=(int n)
{
    *this = *this * n;
    return *this;
}

// pre-increment
Mystring &Mystring::operator++()
{
    for (size_t i=0; i < std::strlen(str); i++)
        str[i] = std::toupper(str[i]);
    return *this;
}

// post increment
Mystring Mystring::operator++(int)
{
    Mystring temp {*this}; // make a copy
    operator++(); // call pre-increment
    return temp; // return the old value
}

std::ostream &operator<<(std::ostream &os, const Mystring &rhs)
{
    os << rhs.str;
    return os;
}