#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "===noboolalpha===" << std::endl;
    std::cout << "noboolalpha (default ) - (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "noboolalpha (default ) - (10 == 20): " << (10 == 20) << std::endl;

    std::cout << "===boolalpha===" << std::endl;
    std::cout << std::boolalpha;
    std::cout << "boolalpha - (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "boolalpha - (10 == 20): " << (10 == 20) << std::endl;

    std::cout << "===toggle to noboolalpha===" << std::endl;
    std::cout << std::noboolalpha;
    std::cout << "noboolalpha - (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "noboolalpha - (10 == 20): " << (10 == 20) << std::endl;

    std::cout << "===setf boolalpha===" << std::endl;
    std::cout.setf(std::ios::boolalpha);
    std::cout << "boolalpha - (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "boolalpha - (10 == 20): " << (10 == 20) << std::endl;

    std::cout << "===resetf boolalpha===" << std::endl;
    std::cout << std::resetiosflags(std::ios::boolalpha);
    // std::cout << std::setiosflags(std::ios::boolalpha);
    std::cout << "boolalpha - (10 == 10): " << (10 == 10) << std::endl;
    std::cout << "boolalpha - (10 == 20): " << (10 == 20) << std::endl;

    int a;
    std::cin >> a;
    return 0;
}