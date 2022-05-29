#include <iostream>
#include <set>
#include <map>
#include <algorithm>


void display_algo(const std::map<std::string, std::set<int>>& m)  
{
    std::cout << "[ ";
    std::for_each(m.begin(), m.end(),
        [](std::pair<std::string, std::set<int>> p)
        { 
            std::cout << p.first << ":[";
            std::for_each(p.second.begin(), p.second.end(),
                [](int i){ std::cout << i; });
            std::cout << "] ";
        });
    std::cout << "]" << std::endl;
}

void display(const std::map<std::string, std::set<int>>& m)  
{
    std::cout << "1[ ";
    for (const auto& map_elem: m)
    {
        std::cout << map_elem.first << ":[ ";
        for (const auto& set_elem: map_elem.second)
            std::cout << set_elem << " ";
        std::cout << "] ";
    }
    std::cout << "]" << std::endl;
}

template <typename T1, typename T2>
void display(const std::map<T1, T2> &m)
{
    std::cout << "2[ ";
    for (const auto &map_elem: m)
        std::cout << map_elem.first << ":" << map_elem.second << " ";        
    std::cout << "]" << std::endl;
}

void test1()
{
    std::cout << "\n===========Test1=============\n";
    std::map<std::string, int> m{
        {"Larry", 1},
        {"Moe", 2},
        {"Curly", 3}
    };
    display(m);

    m.insert(std::pair<std::string, int>{"Anna", 10});
    display(m);

    m.emplace("Anton", 82);
    display(m);

    m.insert(std::make_pair("Joe", 5));
    display(m);

    m["Frank"] = 18;
    display(m);

    m["Frank"] += 10;
    display(m);

    m.erase("Frank");
    display(m);

    std::cout << "Count for Joe: " << m.count("Joe") << std::endl;
    std::cout << "Count for Frank: " << m.count("Frank") << std::endl;

    auto it = m.find("Larry");
    if (it != m.end())
        std::cout << "Found: " << it->first << ":" << it->second << std::endl;

    m.clear();
    display(m);
}

void test2()
{
    std::cout << "\n===========Test2=============\n";
    std::map<std::string, std::set<int>> grades{
        {"Larry", {100, 90}},
        {"Moe", {94}},
        {"Curly", {80, 90, 100}}
    };
    display(grades);

    grades["Larry"].insert(95);
    display(grades);

    auto it = grades.find("Moe");
    if (it != grades.end())
        it->second.insert(1000);
    display(grades);

}

int main()
{    
    test1();
    test2();

    return 0;
}