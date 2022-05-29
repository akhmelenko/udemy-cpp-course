#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Item
{
private:
    std::string name;
    T value;
public:
    Item(std::string name, T value): name{name}, value{value}
    {}
    std::string GetName() const {return name;}
    T GetValue() const {return value;}
};

template <typename T1, typename T2>
struct MyPair
{
    T1 first;
    T2 second;
};

int main()
{    
    Item<int> item1 {"Frank", 100};
    std::cout << item1.GetName() << " " << item1.GetValue() << std::endl;

    Item<std::string> item2{"Frank", "Professor"};
    std::cout << item2.GetName() << " " << item2.GetValue() << std::endl;

    Item<Item<std::string>> item3{"Frank", {"Professor", "C++"}};
    std::cout 
        << item3.GetName() << " " 
        << item3.GetValue().GetName() << " "
        << item3.GetValue().GetValue() << std::endl;

    std::cout << "\n======vector======"<< std::endl;
    std::vector<Item<double>> vec {};
    vec.push_back(Item<double>{"Larry", 100.45});
    vec.push_back(Item<double>{"Moe", 200.45});
    vec.push_back({"Curly", 300.45});

    for (const auto &item: vec)
        std::cout << item.GetName() << " " << item.GetValue() << std::endl;

    std::cout << "\n======pair======" << std::endl;
    MyPair<std::string, int> p1{"Frank", 100};
    MyPair<int, double> p2 {45, 12.54};
    std::cout << p1.first << " " << p1.second << std::endl;
    std::cout << p2.first << " " << p2.second << std::endl;

    return 0;
}