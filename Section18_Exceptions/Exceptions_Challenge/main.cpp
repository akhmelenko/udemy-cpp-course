#include <iostream>
#include <memory>
#include "Account.h"
#include "SavingsAccount.h"
#include "IllegalBalanceException.h"
#include "InsufficentFundsException.h"

using namespace std;

int main()
{
    try
    {
        unique_ptr<Account> pMoesAccount = make_unique<SavingsAccount>("Moe", -100, 5);
        std::cout << "Output account details" << endl;            
    }
    catch (const IllegalBalanceException &ex)
    {
        std::cerr << ex.what() << endl;        
    }
    
    try
    {
        unique_ptr<Account> pLarrysAccount = make_unique<SavingsAccount>("Larry", 100, 1);
        pLarrysAccount->Withdraw(200);
    }
    catch (const InsufficentFundsException &ex)
    {
        std::cerr << ex.what() << endl;        
    }
    
    cout << "Buy!" << endl;
    
	return 0;
}
