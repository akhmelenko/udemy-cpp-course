#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>

class Account
{
    friend std::ostream &operator<<(std::ostream &os, const Account &account);
private:
    static constexpr const char* pDefName = "Unnamed account";
    static constexpr double defBalance = 0.0;
protected:
    std::string name;
    double balance;
public:
    //Account();
    Account(std::string name = pDefName, double balance = defBalance);
    bool Deposit(double amount);
    bool Withdraw(double amount);
    double GetBalance() const;
};

#endif // _ACCOUNT_H_
