#include <iostream>
#include <list>
#include <algorithm>
#include <iterator> // for std::advance

class Person
{
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
    std::string name;
    unsigned int age;
public:
    Person()
        : name{"Unlnown"}, age{0} {};
    Person(const std::string& name, const unsigned int& age)
        : name{name}, age{age} {};
    bool operator<(const Person& rhs)
    {
        return this->age < rhs.age;
    }
    bool operator==(const Person& rhs)
    {
        return this->name == rhs.name && this->age == rhs.age;
    }
};

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os << p.name << ":" << p.age;
    return os;
}

template <typename T>
void display(const std::list<T>& l)
{
    std::cout << "[ ";
    std::for_each(l.begin(), l.end(), [](T x){ std::cout << x << " ";});
    std::cout << "]" << std::endl;
}

void test1()
{
    std::cout << "\n==============Test1================\n";
    std::list<int> l1{1, 2, 3, 4, 5};
    display(l1);

    std::list<std::string> l2;
    l2.push_back("Back");
    l2.push_front("Front");
    display(l2);

    std::list<int> l3;
    l3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(l3);

    std::list<int> l4(10, 100);
    display(l4);
}

void test2()
{
    std::cout << "\n==============Test2================\n";
    std::list<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(l);
    std::cout << "Size = " << l.size() << std::endl;
    std::cout << "Front = " << l.front() << std::endl;
    std::cout << "Back = " << l.back() << std::endl;

    l.clear();
    std::cout << "Size = " << l.size() << std::endl;
}

void test3()
{
    std::cout << "\n==============Test3================\n";
    std::list<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(l);

    l.resize(5);
    display(l);

    l.resize(10);
    display(l);

    std::list<Person> persons;
    persons.resize(5); //uses the Person default constructor
    display(persons);
}

void test4()
{
    std::cout << "\n==============Test4================\n";
    
    std::list<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(l);
    auto it = std::find(l.begin(), l.end(), 5);
    if (it != l.end())
        // insert one element
        l.insert(it, 100);
    display(l);

    std::list<int> l2{1000, 2000, 3000};
    l.insert(it, l2.begin(), l2.end());
    display(l);
    
    std::advance(it, -4); // points to the 100
    std::cout << *it << std::endl;

    l.erase(it);
    display(l);

}

void test5()
{
    std::cout << "\n==============Test5================\n";

    std::list<Person> stooges
    {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 20}
    };
    display(stooges);

    std::string name;
    unsigned int age;
    std::cout << "\nEnter the name of the next stooge";
    getline(std::cin, name);
    std::cout << "\nEnter the age of the next stooge";
    std::cin >> age;
    stooges.emplace_back(name, age);
    display(stooges);

    // insert Frank before Moe
    auto it = std::find(stooges.begin(), stooges.end(), Person("Moe", 25));
    if (it != stooges.end())
        stooges.emplace(it, "Frank", 28);
    display(stooges);
}

void test6()
{
    std::cout << "\n==============Test6================\n";
    
    std::list<Person> stooges {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 20}
    };
    display(stooges);
    
    stooges.sort();
    display(stooges);
}

int main()
{    
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    return 0;
}