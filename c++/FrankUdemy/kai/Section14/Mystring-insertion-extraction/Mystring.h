#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs); 
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);
private:
    char *str;
public:
    Mystring(const char *s = nullptr);
    Mystring(const Mystring &source);
    Mystring(Mystring &&source);
    ~Mystring();
    
    Mystring &operator=(const Mystring &rhs);
    Mystring &operator=(Mystring &&rhs);
    
    
    void display() const;
    
    int get_length() const;
    const char *get_str() const;
};

#endif // MYSTRING_H
