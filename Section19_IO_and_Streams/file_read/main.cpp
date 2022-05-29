#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#if 0
// opening file for reading 
std::fstream inFile {"test.txt", std::ios::in};
// opening file for reading in binary mode
std::fstream inFile {"test.txt", std::ios::in | std::ios::binary};

// openning file only for reading
std::ifstream inFile {"test.txt", std::ios::in};
// the same
std::ifstream inFile {"test.txt"};
// openning file only for reading in bimary mode
std::ifstream inFile {"test.txt", std::ios::binary};

// openning file for input by file name
std::ifstream inFile;
std::string fileName {"test.txt"};
inFile.open(fileName);
//or
inFile.open(fileName, std::ios::binary);

// we need to check if file opened successfuly
if (inFile.is_open()) // if (inFile) // the same
{
    //read it
}
else
{
    //file not opened (need to define the reason)
}

// closing the file
inFile.close();

//reading from files
std::string line[32];
inFile >> line[0] >> line[1];

// the same

// std::string line;
std::getline(inFile, line);

// check for END OF FILE
while (inFile.eof())

// other variant
while(std::getline(inFile, line))

// read file by characters
char c;
while (inFile,get(c))
#endif


int main()
{
    std::ifstream inFile;
    std::string name;
    std::string lastName;
    int age;
    double balance;

    // debugger mode
    // inFile.open("d:\\Anton\\study\\cpp\\Frank\\Section19_Streams\\file_read\\test.txt");
    // build mode
    inFile.open("test.txt");

    if (!inFile)
    {
        std::cerr << "error open file" << std::endl;        
    }
    else
    {
        // while (!inFile.eof())
        // {
        //     // std::getline(inFile, line);
        //     inFile >> line1 >> line2 >> line3;
        //     std::cout << line1 << line2 << line3 << "!" << std::endl;
        // }
        while (inFile >> name >> lastName>> age >> balance)
        {
            // std::getline(inFile, line);
            std::cout 
                << std::setw(10) << std::left << name
                << std::setw(10) << std::left << lastName
                << std::setw(10) << age 
                << std::setw(10) << balance 
            << std::endl;
        }
        inFile.close();
    }
    



    int xxxx;
    std::cin >> xxxx;
    return 0;
}