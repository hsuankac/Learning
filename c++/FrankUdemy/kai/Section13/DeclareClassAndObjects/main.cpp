#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player{
    //attributes
    string name;
    int health;
    int xp;
    // methods
public:
    Player(string name_val = "None", int health_val = 0, int xp_val = 0);
    
};

Player::Player(string name_val, int health_val, int xp_val)
    :name{name_val}, health{health_val}, xp{xp_val}{
        cout << "Three args constructor called" << endl;
    }

int main() {
    Player frank;
    return 0;
}