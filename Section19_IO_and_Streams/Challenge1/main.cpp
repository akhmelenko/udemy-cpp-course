#include <iostream>
#include <iomanip>
#include <vector>

// std::setw(10); - set field width(10) with right justifyed. Works only for next data item after manipulator
// std::left; - set left justifyed. Works only for next data item after manipulator
// std::setfill('-'); - fill free space with charecter. Works for all data items after manipulator

void ruler()
{
    std::cout << "123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890" << std::endl;
}

struct CITY
{
    std::string name;
    int population;
    float price;
};

struct COUNTRY
{
    std::string name;
    std::vector<struct CITY> cities;
};

struct TOUR
{
    std::string tittle;
    std::vector<struct COUNTRY> couintries;
};

struct TOUR tour
    {
        "Our best tours",
        {
            {
                "Russia",
                {
                    {
                        "Moscow", 20000000, 500
                    },
                    {
                        "St.Peterburg", 8000000, 700
                    },
                    {
                        "Kolomna", 140000, 400
                    }
                }
            },
            {
                "UAE",
                {
                    {
                        "Dubai", 25000000, 1500
                    },
                    {
                        "Abu Dhabi", 800000, 1700
                    }
                }
            },
            {
                "France",
                {
                    {
                        "Paris", 29000000, 2500
                    },
                    {
                        "Marsel", 1800000, 2700
                    }
                }
            },
            {
                "Italy",
                {
                    {
                        "Rome", 45000000, 21.1545
                    },
                    {
                        "Palermo", 8200000, 2200
                    }
                }
            }
        }
    };

#define FIELD_WIDTH 15
#define FIELDS_NUMBER 4

int main()
{   
    ruler();
    // tittle
    std::cout << std::setw(FIELD_WIDTH*(FIELDS_NUMBER-1)/2) << std::setfill(' ') << "";
    std::cout << tour.tittle << std::endl;

    // header
    std::cout << std::setw(FIELD_WIDTH*FIELDS_NUMBER) << std::setfill('=') << "" << std::endl;
    std::cout << std::setfill(' ')
        << std::left
            << std::setw(FIELD_WIDTH) << "Country"
            << std::setw(FIELD_WIDTH) << "City"
        << std::right
            << std::setw(FIELD_WIDTH) << "Population"
            << std::setw(FIELD_WIDTH) << "Price"
        << std::endl;
    std::cout << std::setw(FIELD_WIDTH*FIELDS_NUMBER) << std::setfill('=') << "" << std::endl;


    // table
    std::cout << std::setfill(' ');
    for (auto country: tour.couintries)
    {
        std::cout << "\r" << std::setw(FIELD_WIDTH) << std::left << country.name;
        for (auto city: country.cities)
        {
            std::cout
                << std::left
                << std::setw(FIELD_WIDTH) << city.name
                << std::right 
                    << std::setw(FIELD_WIDTH) << city.population 
                    << std::fixed << std::setprecision(2) << std::setw(FIELD_WIDTH) << city.price 
                << std::endl << std::setw(FIELD_WIDTH) << "";
        }
    }

    int xxxx;
    std::cin >> xxxx;
    return 0;
}