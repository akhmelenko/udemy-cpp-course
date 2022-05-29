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

int compareStr(
    const std::string &correctStr,  
    const std::string &checkingStr)
{
    int result {0};
    for (int i = 0; i < correctStr.size(); i++)
    {
        if (correctStr.at(i) == checkingStr.at(i))
            result++;
    }
    return result;
}

int main()
{
    std::ifstream inFile;
    std::string name;
    std::string correctResultStr;
    std::string resultStr;
    int scoreSumm {0};
    const int FIELD_WIDTH {15};
    int cnt {0};

    // debugger mode
    inFile.open("d:\\Anton\\study\\cpp\\Frank\\Section19_Streams\\Challenge2\\test.txt");
    
    // build mode
    // inFile.open("test.txt");

    if (!inFile)
    {
        std::cerr << "error open file" << std::endl;        
    }
    else
    {
        //read correct result
        inFile >> correctResultStr;
        std::cout << "Correct result: " << correctResultStr << std::endl;
        // read students results
        // header
        std::cout 
            << std::setw(FIELD_WIDTH) << std::left << "Student" 
            << std::setw(FIELD_WIDTH) << std::right << "Score"
            << std::endl;
        std::cout << std::setw(FIELD_WIDTH*2) << std::setfill('=') << "" << std::endl;
        std::cout << std::setfill(' ');
        while (inFile >> name >> resultStr)
        {
            int score = compareStr(correctResultStr, resultStr);
            std::cout 
                << std::setw(FIELD_WIDTH) << std::left << name
                << std::setw(FIELD_WIDTH) << std::right << score 
                << std::endl;
            scoreSumm += score;
            cnt++;
        }
        inFile.close();
        std::cout 
                << std::setw(FIELD_WIDTH) << std::left << "Averatge score"
                << std::setw(FIELD_WIDTH) << std::right << (float)scoreSumm/cnt 
                << std::endl;
    }
    



    int xxxx;
    std::cin >> xxxx;
    return 0;
}