#include "SavingsAccount.h"
#include "Account.h"
#include <iostream>

using namespace std;

SavingsAccount::SavingsAccount()
    :interestRate{3.0}
{
}

SavingsAccount::SavingsAccount(std::string name, int ballance, double interestRate)
    :Account(name, ballance), interestRate{interestRate}
{    
}

SavingsAccount::~SavingsAccount()
{
}

double SavingsAccount::GetInterestRate()
{
    return this->interestRate;
}
