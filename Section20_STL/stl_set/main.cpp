#include <iostream>
#include <string>
#include <set>
#include <algorithm>


class Person
{
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
    std::string name;
    unsigned int age;
public:
    Person():
        name{"Unknown"}, age{0} {}
    Person(const std::string& name, const unsigned int& age) 
        : name{name}, age{age} {}
    bool operator<(const Person& rhs) const
    {
        return this->age < rhs.age;
    }
    bool operator==(const Person& rhs) const
    {
        return name == rhs.name && age == rhs.age;
    }
};

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os << p.name << ":" << p.age;
    return os;
}

template <typename T>
void display(std::set<T> s)
{
    std::cout << "[ ";
    std::for_each(s.begin(), s.end(),
        [](T elem){ std::cout << elem << " "; });
    std::cout << "]" << std::endl; 
}

void test1()
{
    std::cout << "\n==========Test1============\n";
    std::set<int> s1{1, 4, 3, 2, 6};
    display(s1);

    s1 = {1, 1, 1, 2, 3, 3, 4, 5, 6, 6, 6};
    display(s1);

    s1.insert(0);
    s1.insert(10);
    display(s1);

    if (s1.count(10))
        std::cout << "10 in set" << std::endl;
    else
        std::cout << "10 not in set" << std::endl;

    auto it = s1.find(5);
    if (it != s1.end())
        std::cout << "Found: " << *it << std::endl;
    
    s1.clear();
    display(s1);
}

void test2()
{
    std::cout << "\n==========Test2============\n";
    std::set<Person> stooges{
        {"Larry", 1},
        {"Moe", 2},
        {"Curly", 3}
    };
    display(stooges); // order of display defined by "operator<"

    stooges.emplace("James", 50);
    display(stooges);

    stooges.emplace("Frank", 50); //NO, 50 is already in set
    display(stooges);

    auto it = stooges.find(Person{"Moe", 2});
    if (it != stooges.end())
        stooges.erase(it);
    display(stooges);

    it = stooges.find(Person{"XXXX", 50}); // Will remove James (uses "operator<")
    if (it != stooges.end())
        stooges.erase(it);
    display(stooges);
}

void test3()
{
    std::cout << "\n==========Test3============\n";
    std::set<std::string> s{"A", "B", "C"};
    display(s);

    std::cout << std::boolalpha;
    auto result = s.insert("D");
    display(s);
    std::cout << "first = " << *result.first << std::endl;
    std::cout << "second = " << result.second << std::endl;

    result = s.insert("A");
    display(s);
    std::cout << "first = " << *result.first << std::endl;
    std::cout << "second = " << result.second << std::endl;
}

int main()
{   
    test1(); 
    test2();
    test3();
    return 0;
}