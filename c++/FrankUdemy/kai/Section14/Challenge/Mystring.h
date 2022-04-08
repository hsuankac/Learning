#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
private:
    char *str; // pointer to a cahr[] that hold a C-style string
public:
    Mystring(const char *s = nullptr);    // overload constructor
    Mystring(const Mystring &source);     // copy constructor
    Mystring(Mystring &&source);          // move constructor
    ~Mystring();                          // destructor
    
    Mystring &operator=(const Mystring &rhs); // copy assignment
    Mystring &operator=(Mystring &&rhs); // move assignment
    
    void display() const;
    int get_length() const;
    const char *get_str() const;
    
    // overload operator member methods
    Mystring operator-() const;                      // make lowercase
    Mystring operator+(const Mystring &rhs) const;   // concatenate
    bool operator==(const Mystring &rhs) const;      // equals
    bool operator!=(const Mystring &rhs) const;      // not equals
    bool operator<(const Mystring &rhs) const;       // less than
    bool operator>(const Mystring &rhs) const;       // greater than
    Mystring &operator+=(const Mystring &rhs);       // s1 += s2; concat and assign
    Mystring operator*(int n) const;                 // s1 = s2 * 3; repeat s2 n times
    Mystring &operator*=(int n);                     // s1 *= 2; s1 = s1 * 3
    Mystring &operator++();                          // pre-increment ++s1
    Mystring operator++(int);                        // post-increment s1++

};

#endif // MYSTRING_H
