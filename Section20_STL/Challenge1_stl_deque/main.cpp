#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>

template <typename T>
void Display(const std::deque<T>& d)
{
    std::cout << "[ ";
    std::for_each(d.begin(), d.end(), [](T x){ std::cout << x << " ";});
    std::cout << "]" << std::endl;
}

void Test1()
{
    std::cout << "\n===============Test1=================\n";
    std::deque<int> d{1, 2, 3, 4, 5};
    Display(d);

    d = {2, 4, 6};
    Display(d);

    std::deque<int> d1(10, 100);
    Display(d1);

    d.at(0) = 0;
    d[1] = 200;
    Display(d);
}

void Test2()
{
    std::cout << "\n===============Test2=================\n";
    std::deque<int> d{0, 0, 0};
    Display(d);

    d.push_back(10);
    d.push_back(20);
    Display(d);

    d.push_front(100);
    d.push_front(200);
    Display(d);

    std::cout << "Front = " << d.front() << std::endl;
    std::cout << "Back = " << d.back() << std::endl;
    std::cout << "Size = " << d.size() << std::endl;

    d.pop_back();
    d.pop_front();
    Display(d);
}

void Test3()
{
    // fron vector even to back, odd to front of deque
    std::cout << "\n===============Test3=================\n";
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::deque<int> d;

    for (const auto& elem: vec)
    {
        if (elem % 2 == 0)
            d.push_back(elem);
        else
            d.push_front(elem);
    }
    Display(d);
}

void Test4()
{
    //push back vs front ordering
    std::cout << "\n===============Test4=================\n";
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::deque<int> d;

    for (const auto& elem: vec)
        d.push_front(elem);
    Display(d);

    d.clear();

    for (const auto& elem: vec)
        d.push_back(elem);
    Display(d);

    

}

void Test5()
{
    // Same test as Test4(), but using std::copy
    std::cout << "\n===============Test5=================\n";
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::deque<int> d;

    std::copy(vec.begin(), vec.end(), std::back_inserter(d));
    Display(d);

    d.clear();

    std::copy(vec.begin(), vec.end(), std::front_inserter(d));
    Display(d);
}

int main()
{    
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}