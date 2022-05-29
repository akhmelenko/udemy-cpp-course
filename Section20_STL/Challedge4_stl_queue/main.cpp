#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iomanip>

template <typename T>
void Display(std::queue<T> q)
{
    std::cout << "[ ";
    while(!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << "]";
}

bool is_palindrome_queue(const std::string &str)
{
    std::queue<unsigned char> q;
    //copy (with lowercase) only letters to deque
    for (const auto& c: str)
    {
        if (std::isalpha(c))
            q.push(std::tolower(c));
    }
    // compare head and tail
    while (q.size() > 1)
    {
        if (q.front() != q.back())
            return false;
        // remove front
        q.pop();
        // move last element to front
        int size = q.size();
        while (size-- > 1)
        {
            q.push(q.front());
            q.pop();
        }
        // remove back
        q.pop();
    }
    return true;
}

bool is_palindrome_queue_stack(const std::string &str)
{
    std::queue<unsigned char> q;
    std::stack<unsigned char> s;
    //copy (with lowercase) only letters to deque
    for (const auto& c: str)
    {
        if (std::isalpha(c))
        {
            q.push(std::tolower(c));
            s.push(std::tolower(c));
        }
    }
    // compare head and tail
    int size = q.size() + 1; // optimization
    while (q.size() > size/2)
    {
        if (q.front() != s.top())
            return false;
        q.pop();
        s.pop();
    }
    return true;
}

int main()
{
    std::cout << std::boolalpha;
    std::vector<std::string> strs{
        "a",
        "aA",
        "Aba",
        "Abba",
        "Nasa",
        "Nasa N",
        "N a s a N",
        "A nut for a jar of tuna.",
        "Amore, Roma."
    };

    for (const auto& str: strs)
        // std::cout << std::setw(6) << std::left << is_palindrome_queue(str) << ": " << str << std::endl;
        std::cout << std::setw(6) << std::left << is_palindrome_queue_stack(str) << ": " << str << std::endl;

    return 0;
}