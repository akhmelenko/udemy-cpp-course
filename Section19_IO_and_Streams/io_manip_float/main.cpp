#include <iostream>
#include <iomanip>

int main()
{
    float a {1234123.5678};
    std::cout << "default : " << a << std::endl;

    double b {123456789.5678};
    std::cout << std::setprecision(9);
    std::cout << "set precision(9): " << b << std::endl;

    double c {123.5678};
    std::cout << std::fixed;
    std::cout << "set fixed(9(default) digits after \".\")): " << c << std::endl;

    double d {123.5678};
    std::cout << std::setprecision(3) << std::fixed;
    std::cout << "setpresicion(3) + fixed(3 digits after \".\")): " << d << std::endl;

    double e {1232569.5678};
    std::cout << std::setprecision(3) << std::scientific;
    std::cout << "setpresicion(3) + scintific (3 digits after \".\" and before \"e\")): " << d << std::endl;
    
    double f {1232569.5678};
    std::cout << std::setprecision(3) << std::scientific << std::uppercase;
    std::cout << "setpresicion(3) + scintific + appercase (3 digits after \".\" and before \"e\")): " << f << std::endl;

    double g {1232569.5678};
    std::cout << std::setprecision(3) << std::scientific << std::uppercase << std::showpos;
    std::cout << "setpresicion(3) + scintific + appercase (3 digits after \".\" and before \"e\")): " << g << std::endl;

    double h {123.56};
    std::cout << std::fixed << std::showpoint;
    std::cout << "showpoint + fixed(6 digits all)): " << h << std::endl;

    double j {1232569.5678};
    std::cout.unsetf(std::ios::uppercase | std::ios::scientific);
    std::cout << "unsetf: " << j << std::endl;

    double k {1232569.5678};
    std::cout << std::resetiosflags(std::ios::floatfield);
    std::cout << "std::cout << std::resetiosflags(std::ios::floatfield): " << k << std::endl;





    int xxxx;
    std::cin >> xxxx;
    return 0;
}