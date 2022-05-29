#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <fstream>

const int WORD_MAX_SIZE = 20;
const int COUNT_MAX_SIZE = 2;

void Display1(const std::map<std::string, int> &m)
{

    std::cout 
        << std::setw(WORD_MAX_SIZE) << std::left << "Word"
        << /*std::setw(COUNT_MAX_SIZE) <<*/ "Count" << std::endl;
    std::cout << "=========================================\n";
    for (const auto &p: m)
    {
        std::cout 
            << std::setw(WORD_MAX_SIZE) << std::left << p.first 
            << std::setw(COUNT_MAX_SIZE) << std::left << p.second
            << std::endl;
    }
    std::cout << std::endl;
}

void part1()
{
    std::ifstream inFile{"text.txt"};
    if (!inFile)
        std::cerr << "Error opening file" << std::endl;
    else
    {
        // read by words
        std::string word;
        std::map<std::string, int> m;
        while (inFile >> word)
        {            
            Display1(m);
            m[word]++;
        }
    }
    inFile.close();
}

void Display2(const std::map <std::string, std::set<int>> &m)
{

    std::cout
        << std::setw(WORD_MAX_SIZE) << std::left << "Word"
        << "Count" << std::endl;
    std::cout << "=========================================\n";
    for (const auto &p : m)
    {
        std::cout
            << std::setw(WORD_MAX_SIZE) << std::left << p.first << "[ ";
        for (const auto &elem : p.second)
            std::cout << elem << " ";
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;
}

void split(
    const std::string &line,
    const char &delimeter,
    std::list<std::string> &words)
{
    std::stringstream ss(line);
    std::string word;
    while (std::getline(ss, word, delimeter))
        words.push_back(word);
}

void part2()
{
    std::ifstream inFile{"text.txt"};
    if (!inFile)
        std::cerr << "Error opening file" << std::endl;
    else
    {
        // read by words
        std::string line;
        std::map<std::string, std::set<int>> m;
        while (std::getline(inFile, line))
        {
            //increment line number
            static int lineNumber = 0;
            lineNumber++;
            // get words from line
            std::list<std::string> words;
            split(line, ' ', words);
            for (const auto& word: words)
                m[word].insert(lineNumber);
            Display2(m);
        }
    }
    inFile.close();
}

int main()
{
    part2();

    return 0;
}