#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool areIsomorphic(const char *s, const char *t) {
    if (strlen(s) != strlen(t)) return false;

    int mapST[256] = {0};  // Mapping from s[i] → t[i]
    int mapTS[256] = {0};  // Mapping from t[i] → s[i]

    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char c1 = (unsigned char)s[i];
        unsigned char c2 = (unsigned char)t[i];

        if (mapST[c1] == 0 && mapTS[c2] == 0) {
            mapST[c1] = c2;
            mapTS[c2] = c1;
        } else {
            if (mapST[c1] != c2 || mapTS[c2] != c1) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    const char *s1 = "paper";
    const char *s2 = "title";

    if (areIsomorphic(s1, s2)) {
        printf("\"%s\" and \"%s\" are isomorphic.\n", s1, s2);
    } else {
        printf("\"%s\" and \"%s\" are NOT isomorphic.\n", s1, s2);
    }

    return 0;
}
