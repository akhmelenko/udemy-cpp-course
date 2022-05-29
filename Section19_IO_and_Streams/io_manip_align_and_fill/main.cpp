#include <iostream>
#include <iomanip>

// std::setw(10); - set field width(10) with right justifyed. Works only for next data item after manipulator
// std::left; - set left justifyed. Works only for next data item after manipulator
// std::setfill('-'); - fill free space with charecter. Works for all data items after manipulator

void ruler()
{
    std::cout << "123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890" << std::endl;
}

int main()
{   
    int num1 {1234};
    double num2 {1234.5678};
    std::string hello {"Hello"};

    std::cout << "\n==Default==" << std::endl;
    ruler();
    std::cout 
        << num1 
        << num2 
        << hello 
        << std::endl;

    std::cout << "\n==Default one per line==" << std::endl;
    ruler();
    std::cout << num1 << std::endl; 
    std::cout << num2 << std::endl; 
    std::cout << hello << std::endl; 

    std::cout << "\n==with 10 for num1==" << std::endl;
    ruler();
    std::cout 
        << std::setw(10) << num1 
        << num2 
        << hello 
        << std::endl;

    std::cout << "\n==with 10 for num1 and num2==" << std::endl;
    ruler();
    std::cout 
        << std::setw(10) << num1 
        << std::setw(10) << num2 
        << hello 
        << std::endl;

    std::cout << "\n==with 10 for num1 and num2 and hello==" << std::endl;
    ruler();
    std::cout 
        << std::setw(10) << num1 
        << std::setw(10) << num2 
        << std::setw(10) << hello 
        << std::endl;

    std::cout << "\n==with 10 for num1 and num2 and hello and left justified for all==" << std::endl;
    ruler();
    std::cout << std::left
        << std::setw(10) << num1 
        << std::setw(10) << num2 
        << std::setw(10) << hello 
        << std::endl;

    std::cout << "\n==with 10 for num1 and num2 and hello and left justified for all and setfill('-')==" << std::endl;
    ruler();
    std::cout << std::left << std::setfill('-')
        << std::setw(10) << num1 
        << std::setw(10) << num2 
        << std::setw(10) << hello 
        << std::endl;

    std::cout << "\n==with 10 for num1 and num2 and hello and left justified for all and different setfill==" << std::endl;
    ruler();
    std::cout << std::left
        << std::setw(10) << std::setfill('-') << num1 
        << std::setw(10) << std::setfill('#') << num2 
        << std::setw(10) << std::setfill('*') << hello 
        << std::endl;        



    int xxxx;
    std::cin >> xxxx;
    return 0;
}