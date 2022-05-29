#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <list>

class Person
{
    std::string name;
    unsigned int age;
public:
    Person() = default;
    Person(const std::string& name, const unsigned int& age): name{name}, age{age}{}
    bool operator<(const Person& rhs) const
    {
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs) const
    {
        return this->name == rhs.name && this->age == rhs.age;
    }
};

// Find elements in container
void FindTest()
{
    std::cout << "\n==== FIND =====\n";

    std::cout << "\n==== std::vector<int> =====\n";
    std::vector<int> vec {1, 2, 3, 4, 5};
    // finde FIRST occucance of element
    auto loc = std::find(std::begin(vec), std::end(vec), 1);
    if (loc != std::end(vec))
        std::cout << "Found the number " << *loc << std::endl;
    else
        std::cout << "Can`t found the number " << std::endl;


    std::cout << "\n==== std::list<Person> =====\n";
    std::list<Person> players
    {
        {"Larry", 20},
        {"Moe", 25},
        {"Curly", 21}
    };
    // finde FIRST occucance of element
    auto locP = std::find(std::begin(players), std::end(players), Person{"Moe", 25});
    if (locP != std::end(players))
        std::cout << "Found Moe" << std::endl;
    else
        std::cout << "Can`t found Moe" << std::endl;
}

// count specific elements in container
void CountTest()
{
    std::cout << "\n==== COUNT =====\n";
    std::cout << "\n==== std::vector<int> =====\n";
    std::vector<int> vec {1, 2, 3, 1, 4, 5, 1, 6, 7, 1};
    unsigned int cnt = std::count(vec.begin(), vec.end(), 1);
    std::cout << cnt << " occurrences found" << std::endl;
}

// count elements in container witch match condition
void CountIfTest()
{
    std::cout << "\n==== COUNT IF =====\n";
    std::cout << "\n==== std::vector<int> =====\n";
    std::vector<int> vec{1, 2, 3, 1, 4, 5, 1, 6, 7, 100};
    
    //count the even elements
    unsigned int cnt = std::count_if(vec.begin(), vec.end(), [](int x){ return (x%2) == 0;});
    std::cout << cnt << " even found" << std::endl;
    //count the odd elements
    cnt = std::count_if(vec.begin(), vec.end(), [](int x) { return (x%2) != 0; });
    std::cout << cnt << " odd found" << std::endl;

    //count the elements witch >= 5
    cnt = std::count_if(vec.begin(), vec.end(), [](int x) { return x >= 5; });
    std::cout << cnt << " elements >= 5" << std::endl;
}

void ReplaceTest()
{
    std::cout << "\n==== REPLACE =====\n";
    std::cout << "\n==== std::vector<int> =====\n";
    std::vector<int> vec{1, 2, 3, 1, 4, 5, 1, 6, 7, 100};

    std::cout << "[ ";
    for (const auto& elem: vec)
        std::cout << elem << " ";
    std::cout << "]" << std::endl;

    std::replace(vec.begin(), vec.end(), 1, 555);

    std::cout << "[ ";
    for (const auto &elem : vec)
        std::cout << elem << " ";
    std::cout << "]" << std::endl;
}

void AllOfTest()
{
    std::cout << "\n==== All Of =====\n";
    std::cout << "\n==== std::vector<int> =====\n";
    std::vector<int> vec{1, 2, 3, 1, 4, 5, 1, 6, 7, 100};

    if (std::all_of(vec.begin(), vec.end(), [](int x){ return x > 10;}))
        std::cout << "All elements are > 10" << std::endl;
    else
        std::cout << "Not all elements are > 10" << std::endl;

    if (std::all_of(vec.begin(), vec.end(), [](int x) { return x < 101; }))
        std::cout << "All elements are < 101" << std::endl;
    else
        std::cout << "Not all elements are < 101" << std::endl;
}

void StringTransformTest()
{
    std::cout << "\n==== STRING TRANSFORM =====\n";
    std::string str {"This is a string"};
    std::string str2 {"   "};
    std::cout << "Before transform: " << str << std::endl;

    std::transform(str.begin(), str.end(), str2.begin(), ::toupper);
    std::cout << "After transform str: " << str << std::endl;
    std::cout << "After transform str2: " << str2 << std::endl;
}

int main()
{
    FindTest();
    CountTest();
    CountIfTest();
    ReplaceTest();
    AllOfTest();
    StringTransformTest();

    return 0;
}