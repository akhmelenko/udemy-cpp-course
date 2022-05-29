#include <iostream>
#include <string>
#include <vector>

template <int N>
class Array
{
    int size = N;
    int values[N];
    friend std::ostream &operator<<(std::ostream &os, const Array &array)
    {
        os << "[ ";
        for (const auto &value : array.values)
        {
            os << value << " ";
        }
        os << " ]";
        return os;
    }
public:
    Array() = default;
    Array(int value)
    {
        for (auto &item: values)
            item = value;
    }
    void Fill(int value)
    {
        for (auto &item: values)
            item = value;
    }
    int GetSize()
    {
        return size;
    }
};

int main()
{    
    Array<5> nums;
    std::cout << nums << std::endl;

    return 0;
}