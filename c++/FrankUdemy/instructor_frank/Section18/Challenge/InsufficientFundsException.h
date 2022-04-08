#ifndef _INSUFFICIENT_FUNDS_EXCEPTION_H
#define _INSUFFICIENT_FUNDS_EXCEPTION_H

class InsufficientFundsException: public std::exception
{
public:
    InsufficientFundsException() noexcept = default;
    ~InsufficientFundsException() = default;
    virtual const char *what() const noexcept{
        return "Insufficient funds exception";
    }
};

#endif