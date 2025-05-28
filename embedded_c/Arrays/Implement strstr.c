#include <stdio.h>

char* myStrStr(const char* haystack, const char* needle) {
    if (!*needle)  // Empty needle
        return (char*)haystack;

    for (; *haystack; haystack++) {
        const char *h = haystack;
        const char *n = needle;

        while (*h && *n && *h == *n) {
            h++;
            n++;
        }

        if (!*n)  // Reached end of needle, match found
            return (char*)haystack;
    }

    return NULL;  // No match found
}

int main() {
    const char *haystack = "hello world";
    const char *needle = "world";

    char *result = myStrStr(haystack, needle);

    if (result)
        printf("Substring found at position: %ld\n", result - haystack);
    else
        printf("Substring not found.\n");

    return 0;
}
