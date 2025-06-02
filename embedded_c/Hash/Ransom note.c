// Given two strings ransomNote and magazine, 
// return true if ransomNote can be constructed by using 
// letters from magazine. Each letter in magazine can only be used once.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool canConstruct(char *ransomNote, char *magazine)
{
    int letters[26] = {0}; // frequency count for 'a' to 'z'

    // count each letter in magazine
    for(int i = 0; magazine[i] != '\0'; i++){
        letters[magazine[i] - 'a']++;
    }

    // subtract letter counts for ransomNote
    for(int i = 0; ransomNote[i] != '\0'; i++){
        if(--letters[ransomNote[i] - 'a'] < 0){
            return false;
        }
    }
    return true;
}

int main() {
    char ransomNote[] = "aabbcc";
    char magazine[] = "aabbccddee";

    if (canConstruct(ransomNote, magazine)) {
        printf("Can construct ransom note.\n");
    } else {
        printf("Cannot construct ransom note.\n");
    }

    return 0;
}