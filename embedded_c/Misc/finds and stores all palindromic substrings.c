#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define             MAX_CAPACITY            100

typedef struct {
    int capacity;
    int size;
    char **items;
} StringList;

// initialize string list
void initStringList(StringList *list) {
    list->capacity = MAX_CAPACITY;
    list->size = 0;
    list->items = (char**)malloc(sizeof(char*) * list->capacity);
}

void addSubstring(StringList *result, char *s, int left, int right) {
    int len = right - left + 1;
    char *substr = (char*)malloc(sizeof(char) * (len + 1));
    strncpy(substr, s + left, len);
    substr[len] = '\0';
    if(result->size == result->capacity) {
        result->capacity *= 2;
        result->items = (char**)realloc(result->items, result->capacity * sizeof(char *));
    }
    result->items[result->size++] = substr;
}

void expandCollect(char *s, int left, int right, StringList *result) {
    while(left >= 0 && s[right] != '\0' && s[left] == s[right]) {
        addSubstring(result, s, left, right);
        left--;
        right++;
    }
}

StringList getAllPalindromicSubstrings(char *s) {
    StringList result;
    initStringList(&result);
    int n = strlen(s);
    for(int i = 0; i < n; i++) {
        // odd length palindroms
        expandCollect(s, i, i, &result);

        // even length palindroms
        expandCollect(s, i, i + 1, &result);
    }

    return result;
}

void freeStringList(StringList *result) {
    for(int i = 0; i < result->size; i++) {
        free(result->items[i]);
    }
    free(result->items);
}

int main() {
    char s[] = "abbaeae";
    StringList palindromes = getAllPalindromicSubstrings(s);

    printf("Palindromic substrings found (%d total):\n", palindromes.size);
    for(int i = 0; i < palindromes.size; i++) {
        printf("%s\n", palindromes.items[i]);
    }

    freeStringList(&palindromes);
    return 0;
}