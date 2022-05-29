#include <iostream>
#include <vector>
#include <algorithm>

struct SquarePrintFunctor
{
    void operator()(int x) //overloaded operator ()
    {
        std::cout << x * x << std::endl;
    }
};

void Square(int x)
{
    std::cout << x * x << std::endl;
}

int main()
{
    std::vector<int> vec{1, 2, 3, 4};
    
    std::cout << "\n=========== using functor ==================\n";
    SquarePrintFunctor square; // function object
    std::for_each(vec.begin(), vec.end(), square);

    std::cout << "\n=========== using function ptr ==================\n";
    std::for_each(vec.begin(), vec.end(), Square);

    std::cout << "\n=========== using lambda expression ==================\n";
    std::for_each(vec.begin(), vec.end(), 
                    [](int x){ std::cout << x * x << std::endl;});

    return 0;
}