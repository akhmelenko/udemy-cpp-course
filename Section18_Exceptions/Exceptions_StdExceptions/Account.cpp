#include "Account.h"
#include "IllegalBalanceException.h"
#include <iostream>

using namespace std;

Account::Account(std::string name, int balance)
    :balance{balance}, name{name}
{
    //check for exception
    if (balance < 0)
        throw IllegalBalanceException{};
}

Account::Account()
    : Account("Empty Account", 0.0)
{
}

Account::~Account()
{
}

double Account::GetBalance()
{
    return this->balance;
}

void Account::Deposit(double amount)
{
    cout << "Account deposit called with " << amount << endl;
    balance += amount;
}

void Account::Withdraw(double amount)
{
    cout << "Account withdraw called with " << amount << endl;
    if ((this->balance - amount) > 0)
        this->balance -= amount;
    else
       cout << "Account withdraw ERR: not enough money!" << endl; 
}