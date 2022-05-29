#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#if 0
// opening file for write
std::fstream outFile {"text.txt", std::ios::out};
//or
std::fstream outFile;
outFile.open("text.txt", std::ios::out);
// or open for write binary
outFile.open("text.bin", std::ios::out | std::ios::binary); 

//the same

// opening file for write
std::ofstream outFile {"text.txt", std::ios::out};
//or
std::ofstream outFile;
outFile.open("text.txt");
// or open for write binary
outFile.open("text.bin", std::ios::binary);

// truncate (discard content) when opening (DEFAULT)
std::ofstream outFile {"text.txt", std::ios::trunc};

// append (to the end) when opening
std::ofstream outFile {"text.txt", std::ios::app};

// set initial position to the end of the file when opening
std::ofstream outFile {"text.txt", std::ios::ate};

// always close the file
outFile.close();

// writing to file:
int num {100};
float total {45.78};
std::string name {"Frank"}; 

outFile 
    << num << "\n"
    << total << "\n"
    << name << std::endl; // std::endl - flushes out any unread buffers


#endif


int main()
{
    std::ifstream inFile {"origin.txt"};
    std::ofstream outFile {"copy.txt"};

    if (!inFile)
    {
        std::cerr << "Input file not opened" << std::endl;
        return 1;
    }
    if (!outFile)
    {
        std::cerr << "Output file not opened" << std::endl;
        return 1;
    }
    std::string line {};
    int lineNumber {1};
    while (std::getline(inFile, line))
    {
        // if (line.size() > 0)
        if (line != "")
        {
            outFile 
                << std::setw(6) << std::left << lineNumber 
                << line;
            lineNumber++;
        }
        outFile << std::endl;

    }
    inFile.close();
    outFile.close();


    return 0;
}