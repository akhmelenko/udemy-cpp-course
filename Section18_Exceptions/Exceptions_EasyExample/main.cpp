#include <iostream>

using namespace std;

int main()
{
    int km {0};
    int liters {0};
    
    cout << "Enter liters: ";
    cin >> liters;
    cout << "Enter kilometers: ";
    cin >> km;
    
    try
    {
        if (km == 0)
            throw 0;
        double averageConsumption = static_cast<double>(liters) / km;
        cout << "Your consumption = " << averageConsumption << " liters / km" << endl;
    }
    catch (int &ex)
    {
        std::cerr << "Can`t divide by 0!" << endl;
    }
    
    cout << "Bye" << endl;
    
	return 0;
}
