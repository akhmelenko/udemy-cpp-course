#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>

void Display(const std::vector<int> &vec)
{
    std::cout << "[ ";
    for (const auto &i: vec)
        std::cout << i << " ";
    std::cout << "]" << std::endl;
}

void Test1()
{
    std::cout << "\n=============1============\n";
    std::vector<int> nums {1, 2, 3, 4, 5};
    auto it = nums.begin(); //point to 1
    std::cout << *it << std::endl;

    it++; // point to 2
    std::cout << *it << std::endl;

    it +=2; // point to 4
    std::cout << *it << std::endl;

    it -= 2; // point to 2
    std::cout << *it << std::endl;

    it = nums.end() - 1; // point to 5
    std::cout << *it << std::endl;
}

void Test2()
{
    std::cout << "\n=============2============\n";
    std::vector<int> nums{1, 2, 3, 4, 5};    

    //display all elements of vector
    std::vector<int>::iterator it = nums.begin(); //point to 1
    while (it != nums.end())
    {
        std::cout << *it << " ";
        ++it;
    }

    //change all vector elements to 0
    it = nums.begin(); //point to 1
    while (it < nums.end())
    {
        *it = 0;
        ++it;
    }

    Display(nums);
}

void Test3()
{
    std::cout << "\n=============3============\n";
    std::vector<int> nums{1, 2, 3, 4, 5};

    //display all elements of vector
    std::vector<int>::const_iterator it = nums.begin(); //point to 1
    //auto it = nums.cbegin();
    while (it != nums.end())
    {
        std::cout << *it << "\n";
        ++it;
    }

    //change all vector elements to 0
    it = nums.begin(); //point to 1
    while (it < nums.end())
    {
        //*it = 0; //compyler error - read only
        ++it;
    }
}

void Test4()
{
    std::cout << "\n=============4============\n";
    std::vector<int> nums{1, 2, 3, 4, 5};

    //reverse iterator over a vector
    auto rIt = nums.rbegin(); //point to 5
    //auto it = nums.cbegin();
    while (rIt != nums.rend())
    {
        std::cout << *rIt << "\n";
        ++rIt;
    }


    //const reverse iterator over a list
    std::list<std::string> names {"Larry", "Moe", "Curly"};
    auto crIt = names.crbegin(); //point to Curly
    std::cout << "\n" << *crIt << "\n";
    crIt++; //point to Moe
    std::cout << *crIt << "\n";
    crIt++; //point to Larry
    std::cout << *crIt << "\n\n";

    //iterator over the map
    std::map<std::string, std::string> favorites 
    {
        {"Frank", "C++"},
        {"Bill", "Java"},
        {"James", "Haskell"}
    };
    auto mIt = favorites.begin();
    while (mIt != favorites.end())
    {
        std::cout << mIt->first << ":" << mIt->second << '\n';
        mIt++;
    }
}

void Test5()
{
    std::cout << "\n=============5============\n";
    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto start = vec.begin() + 2;
    auto finish = vec.end() - 3;

    while(start != finish)
    {
        std::cout << *start << std::endl;
        start++;
    }
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