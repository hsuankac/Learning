#include <iostream>
using namespace std;

// This program will calculate the area of a room in square feet

int main() {
    cout << "Enter the width of the room: ";
    int room_width {0};
    cin >> room_width;
    
    cout << "Enter the length of the room: ";
    int room_legnth {0};
    cin >> room_legnth;
    
    cout << "The area of the room is " << room_width * room_legnth << " square feet" << endl;
    return 0;
}