#ifndef ILLEGAL_BALANCE_EXCEPTION_H
#define ILLEGAL_BALANCE_EXCEPTION_H

class IllegalBalanceException// : public std::exception
{    
public:
    IllegalBalanceException() noexcept = default;
    ~IllegalBalanceException() = default;
    virtual const char* what() const noexcept
    {
        return "Illegal balance exception!";
    }
};

#endif// ILLEGAL_BALANCE_EXCEPTION_H