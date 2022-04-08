#ifndef MYSTRING_H
#define MYSTRING_H

class Mystring
{
private:
    char *str; // pointer to a cahr[] that hold a C-style string
public:
    Mystring(const char *s = nullptr);
    Mystring(const Mystring &source);
    ~Mystring();
    void display() const;
    int get_length() const;
    const char *get_str() const;

};

#endif // MYSTRING_H
