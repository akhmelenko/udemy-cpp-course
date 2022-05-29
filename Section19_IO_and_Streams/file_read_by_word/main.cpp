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

// we nee to check if file opened successfuly
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
        while (inFile >> name)
        {
            std::cout << name << std::endl;
        }
        inFile.close();
    }
    



    int xxxx;
    std::cin >> xxxx;
    return 0;
}