#include <iostream>
#include <vector>
#include <algorithm>


int main()
{    
    std::vector<int> vec {1, 2, 3, 4};
    auto loc = std::find(vec.begin(), vec.end(), 3);
    if (loc != vec.end())
        std::cout << *loc << std::endl;

    return 0;
}