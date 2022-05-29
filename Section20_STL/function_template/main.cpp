#include <iostream>
#include <string>


template <typename T0, typename T1>
T1 Max(T0 a, T1 b)
{
    return (a > b) ? a : b;
}

template <typename T1, typename T2>
void MyPrint(T1 a, T2 b)
{
    std::cout << a << " " << b << std::endl;
}

struct Person
{  
    std::string name;
    unsigned int age;
    bool operator>(const Person &rhs) const
    {
        return this->age > rhs.age;
    }
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << p.name << " " << p.age;
    return os;
}

template <typename T>
void MySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{    
    int a = 5;
    int b = 7;
    std::cout << "int Max(a,b) = " << Max(a, b) << std::endl;

    double c = 5.5;
    double d = 7.7;
    std::cout << "double Max(c,d) = " << Max(c, d) << std::endl;

    char e = 8;
    double f = 7.7;
    std::cout << "char and double Max(e,f) = " << Max(e, f) << std::endl;

    std::cout << "Max<double, int>(10.45, 10) = " << Max<double, int>(10.45, 10) << std::endl;
    std::cout << "Max<double>(10.45, 10) = " << Max<double>(10.45, 10) << std::endl;
    std::cout << "deduce 'int': Max(45, 10) = " << Max(45, 10) << std::endl; //deduce "int"
    std::cout << "deduce 'char': Max('A', 'C') = " << Max('A', 'C') << std::endl; //deduce "char"
    std::cout << "deduce 'float': Max(5.45, 7.32) = " << Max(5.45, 7.32) << std::endl; //deduce "float"
    std::cout << "deduce 'int': Max(45/3 + 2*7, 4 + 5*8) = " << Max(45 / 3 + 2 * 7, 4 + 5 * 8) << std::endl; //deduce "int"

    Person p1 {"Moe", 55};
    Person p2 {"Curly", 52};

    Person p3 = Max(p1, p2);
    std::cout << "Max(p1, p2) = " << p3.name << " is older" << std::endl;
    
    
    MyPrint(p1, p2);

    MyPrint<int, int>(10, 20);
    MyPrint(10, 20);
    MyPrint<char, double>('A', 20.54);
    MyPrint('A', 20.54);
    MyPrint(1000, "test");
    MyPrint(2000, std::string{"Frank"});

    int a1 {100};
    int a2 {2000};

    std::cout << "a1 = " << a1 << ", a2 = " << a2 << std::endl;
    MySwap(a1, a2);
    std::cout << "after swap..." << std::endl;
    std::cout << "a1 = " << a1 << ", a2 = " << a2 << std::endl;

    std::cout << "p1 = " << p1 << ", p2 = " << p2 << std::endl;
    MySwap(p1, p2);
    std::cout << "after swap..." << std::endl;
    std::cout << "p1 = " << p1 << ", p2 = " << p2 << std::endl;

    return 0;
}