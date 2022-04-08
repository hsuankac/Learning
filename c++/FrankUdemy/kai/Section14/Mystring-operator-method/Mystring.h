#ifndef MYSTRING_H
#define MYSTRING_H

class Mystring
{
private:
    char *str;
public:
    Mystring(const char *s = nullptr);
    Mystring(const Mystring &source);
    Mystring(Mystring &&source);
    ~Mystring();
    
    Mystring &operator=(const Mystring &rhs);
    Mystring &operator=(Mystring &&rhs);
    
    Mystring operator-() const;     // make lower        
    Mystring operator+(const Mystring &rhs) const; //concatenate
    bool operator==(const Mystring &rhs) const;
    
    void display() const;
    
    int get_length() const;
    const char *get_str() const;
};

#endif // MYSTRING_H
