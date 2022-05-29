#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>

class Person
{
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
    std::string name;
    int age;
public:
    Person(): name{"Unknown"}, age{0} {}
    Person(std::string name, int age): name{name}, age{age} {}
    bool operator<(const Person& rhs) const
    {
        return age < rhs.age;
    }
    bool operator==(const Person& rhs) const
    {
        return name == rhs.name && age == rhs.age;
    }
};

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    std::cout << p.name << ":" << p.age;
} 

template <typename T>
void display(std::priority_queue<T> pq)
{
    std::cout << "[ ";
    while (!pq.empty())
    {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << "]" << std::endl;
}

void test1()
{
    std::cout << "\n=========Test1============\n" << std::endl;
    std::priority_queue<int> pq;

    for (int i: {0,3,4,5,1,2,33,45,56,556,3,4,5,})
        pq.push(i);
    std::cout << "Size:" << pq.size() << std::endl;
    std::cout << "Top: " << pq.top() << std::endl;
    display(pq);

    pq.pop();
    display(pq);
}

void test2()
{
    std::cout << "\n=========Test2============\n" << std::endl;
    std::priority_queue<Person> pq;

    pq.push(Person{"A", 50});
    pq.push(Person{"B", 5});
    pq.push(Person{"C", 10});
    pq.push(Person{"D", 1});
    pq.push(Person{"E", 3});
    pq.push(Person{"F", 27});
    pq.push(Person{"G", 7});
    pq.push(Person{"H", 12});

    display(pq);
}

int main()
{
    test1();
    test2();

    return 0;
}

