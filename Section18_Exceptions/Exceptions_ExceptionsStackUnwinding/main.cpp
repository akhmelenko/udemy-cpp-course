#include <iostream>

using namespace std;

void FunctionC()
{
    cout << "Function C start" << endl;
    throw 100;
    cout << "Function C Finish" << endl;
}

void FunctionB()
{
    cout << "Function B start" << endl;
    FunctionC();
    cout << "Function B Finish" << endl;
}

void FunctionA()
{
    cout << "Function A start" << endl;
    FunctionB();
    cout << "Function A Finish" << endl;
}



int main()
{
	cout << "Main start" << endl;
    try
    {
        FunctionA();
    }
    catch (int & ex)
    {
         cout << "Exception!!!" << endl;
    }
    
    cout << "Main end" << endl;
	return 0;
}
