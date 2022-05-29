#ifndef INSUFFICENT_FUNDS_EXCEPTION_H
#define INSUFFICENT_FUNDS_EXCEPTION_H

class InsufficentFundsException// : public std::exception
{    
public:
    InsufficentFundsException() noexcept = default;
    ~InsufficentFundsException() = default;
    virtual const char* what() const noexcept
    {
        return "Insufficent Funds exception!";
    }
};

#endif// INSUFFICENT_FUNDS_EXCEPTION_H