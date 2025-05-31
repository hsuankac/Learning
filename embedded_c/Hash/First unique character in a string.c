#include <stdio.h>
#include <string.h>

// single pass approach
// int firstUniqCharSinglePass(const char *s) {
//     int count[256] = {0};
//     int index[256];

//     for (int i = 0; i < 256; i++) {
//         index[i] = -1;
//     }

//     for (int i = 0; s[i]; i++) {
//         unsigned char ch = (unsigned char)s[i];

//         count[ch]++;
//         if (count[ch] == 1) {
//             index[ch] = i;  // first time seen
//         } else {
//             index[ch] = -1; // now it's repeated
//         }
//     }

//     // Find minimum index of any char seen exactly once
//     int minIndex = -1;
//     for (int i = 0; i < 256; i++) {
//         if (index[i] != -1) {
//             if (minIndex == -1 || index[i] < minIndex) {
//                 minIndex = index[i];
//             }
//         }
//     }

//     return minIndex;
// }

int firstUniqChar(const char *s) {
    int count[256] = {0};  // ASCII range

    // Step 1: Count character frequencies
    for (int i = 0; s[i]; i++) {
        count[(unsigned char)s[i]]++;
    }

    // Step 2: Find first character with frequency 1
    for (int i = 0; s[i]; i++) {
        if (count[(unsigned char)s[i]] == 1) {
            return i;  // Return index of first unique character
        }
    }

    return -1;  // No unique character found
}

int main() {
    const char *str = "leetcode";
    int idx = firstUniqChar(str);

    if (idx != -1) {
        printf("First unique character: '%c' at index %d\n", str[idx], idx);
    } else {
        printf("No unique character found.\n");
    }

    return 0;
}
