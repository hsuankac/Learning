#include "Mystring.h"
#include <cstring>
#include <cctype>
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
    std::cout << "copy assignment" << std::endl;
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
    std::cout << "Using move assignment" << std::endl;
    if(this == &rhs)
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// equality
bool Mystring::operator==(const Mystring &rhs) const
{
    return (std::strcmp(str, rhs.str) == 0);
}

// make lowercase
Mystring Mystring::operator-() const
{
    char *buff = new char [std::strlen(str) + 1];
    std::strcpy(buff, str);
    for(size_t i = 0; i < std::strlen(str); i++)
        buff[i] = std::tolower(buff[i]);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

// concatenate
Mystring Mystring::operator+(const Mystring &rhs) const
{
    char *buff = new char [std::strlen(this->str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, this->str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;    
}

// copy constructor
Mystring::Mystring(const Mystring &source)
    :str{nullptr}
{
    str = new char [std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
    std::cout << "copy constructor used" << std::endl;
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