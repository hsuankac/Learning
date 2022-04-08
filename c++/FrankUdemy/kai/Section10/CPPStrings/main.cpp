#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    
//    string s0;
//    string s1 {"Apple"};
//    string s2 {"Banana"};
//    string s3 {"Kiwi"};
//    string s4 {"apple"};
//    string s5 {s1}; // Apple
//    string s6 {s1, 0, 3}; // App
//    string s7 (10, 'X'); //XXXXXXXXXX 
//    
//    cout << s0 << endl;
//    cout << s0.length() << endl;
//    
//    cout << "s7 is initialized to: " << s7 << endl;
//    
    cout << "Find" << "\n---------------------" << endl;
    string s1 {"The secret word is boo"};
    
    string word {};

    cout << "Enter the word to find: ";
    cin >> word;
    
    size_t position = s1.find(word);
    if(position != string::npos)
        cout << "Found " << word << " at position: " << position << endl;
    else
        cout << "word not found" << endl;
        
    return 0;
}