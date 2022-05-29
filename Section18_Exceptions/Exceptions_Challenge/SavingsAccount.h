#ifndef _SAVINGSACCOUNT_H_
#define _SAVINGSACCOUNT_H_

#include "Account.h"

class SavingsAccount : public Account
{
public:
    double interestRate;

    SavingsAccount();
    SavingsAccount(std::string name, int ballance, double interestRate);
    ~SavingsAccount();
    
    double GetInterestRate();
};

#endif // _SAVINGSACCOUNT_H_
