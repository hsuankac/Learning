#include <iostream>
#include "Player.h"

using namespace std;

void display_active_players()
{
    cout << "Active players: " << Player::get_num_players() << endl;
}

int main() {
    display_active_players();
    Player Kai {"Kai", 100, 100};
     display_active_players();
    return 0;
}