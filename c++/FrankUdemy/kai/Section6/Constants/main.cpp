#include <iostream>

using namespace std;

int main() {
    cout << "Hello, welcome to Kai's carpet cleaning service" << endl;
    cout << "\nHow many rooms would you like to cleaned? ";
    
    int number_of_rooms {0};
    cin >> number_of_rooms;
    
    const double price_per_room {30.0};
    const double sales_tax {0.06};
    const int estimate_expiry {30}; // days
    
    cout << "\nEstimate for carpet cleaning service" << endl;
    cout << "Number of rooms: "<< number_of_rooms << endl; 
    cout << "Price per room: $" << price_per_room << endl;
    cout << "Cost: $" << number_of_rooms * price_per_room << endl;
    cout << "Tax: $" << price_per_room * number_of_rooms * sales_tax << endl;
    
    cout << "==========================================" << endl;
    cout << "Total estimate: $" << (price_per_room * number_of_rooms) + (price_per_room * number_of_rooms * sales_tax) << endl;
    cout << "This estimate is valid for " << estimate_expiry << " days" << endl;
    
    return 0;
}