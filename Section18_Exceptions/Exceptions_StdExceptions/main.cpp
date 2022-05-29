#include <iostream>
#include <memory>
#include "Account.h"
#include "SavingsAccount.h"
#include "IllegalBalanceException.h"

using namespace std;

int main()
{
    try
    {
        unique_ptr<Account> pMoesAccount = make_unique<SavingsAccount>("Moe", -10, 5);
        std::cout << "Output account details" << endl;
    }
    catch (const IllegalBalanceException &ex)
    {
        std::cerr << ex.what() << endl;        
    }
    
    cout << "Buy!" << endl;
    
	return 0;
}
