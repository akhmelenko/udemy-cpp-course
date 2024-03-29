#include <iostream>

using namespace std;

double AverageConsumption(int liters, int km)
{
    if (km == 0)
        throw 0;
    return static_cast<double>(liters) / km;
}

int main()
{
    int km {0};
    int liters {0};
    double litersPerKm {0.0};
    
    cout << "Enter liters: ";
    cin >> liters;
    cout << "Enter kilometers: ";
    cin >> km;
    
    try
    {
        litersPerKm = AverageConsumption(liters, km);
        cout << "Your consumption = " << litersPerKm << " liters / km" << endl;
    }
    catch (int &ex)
    {
        std::cerr << "Can`t divide by 0!" << endl;
    }
    
    cout << "Bye" << endl;
    
	return 0;
}
