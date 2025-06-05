#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INITIAL_CAPACITY            100
#define HASH_TABLE_SIZE             1009            // a prime number for better distribution

// hash table entry
typedef struct Entry {
    char *key;
    struct Entry *next;
} Entry;

// hash set
typedef struct {
    Entry **bucket;
} HashSet;

// basic hash table with open addressing and string comparison to avoid storing duplicate substrings

// string hashing
unsigned long hashString(const char *str) {
    unsigned long hash = 5381;
    while(*str) {
        hash = ((hash << 5) + hash) + (unsigned char)(*str++);
    }
    return hash;
}

void initHashSet(HashSet *set) {
    set->bucket = (Entry**)calloc(HASH_TABLE_SIZE, sizeof(Entry*));
}

bool hashSetContains(HashSet *set, const char *str) {
    unsigned long hash = hashString(str) % HASH_TABLE_SIZE;
    Entry *curr = set->bucket[hash];
    while(curr) {
        if(strcmp(curr->key, str) == 0)
            return true;
        curr = curr->next;
    }
    return false;
}

void hashSetInsert(HashSet *set, const char *str) {
    if(hashSetContains(set, str))
        return;
    unsigned long hash = hashString(str) % HASH_TABLE_SIZE;
    Entry *newEntry = (Entry*)malloc(sizeof(Entry));
    newEntry->key = strdup(str);
    newEntry->next = set->bucket[hash];
    set->bucket[hash] = newEntry;
}

void freeHashSet(HashSet *set) {
    for(int i = 0; i < HASH_TABLE_SIZE; i++) {
        Entry *curr = set->bucket[i];
        while(curr) {
            Entry *tmp = curr;
            curr = curr->next;
            free(tmp->key);
            free(tmp);
        }
    }
    free(set->bucket);
}

// === Dynamic List of Strings ===
typedef struct {
    char **items;
    int size;
    int capacity;
} StringList;

void initStringList(StringList *list) {
    list->capacity = INITIAL_CAPACITY;
    list->size = 0;
    list->items = (char **)malloc(list->capacity * sizeof(char *));
}

void addToStringList(StringList *list, const char *str) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->items = (char **)realloc(list->items, list->capacity * sizeof(char *));
    }
    list->items[list->size++] = strdup(str);
}

void freeStringList(StringList *list) {
    for (int i = 0; i < list->size; i++)
        free(list->items[i]);
    free(list->items);
}

// === Palindromic Expansion ===
void expandAndCollectUnique(const char *s, int left, int right, StringList *result, HashSet *seen) {
    while (left >= 0 && s[right] != '\0' && s[left] == s[right]) {
        int len = right - left + 1;
        char *substr = (char *)malloc(len + 1);
        strncpy(substr, s + left, len);
        substr[len] = '\0';

        if (!hashSetContains(seen, substr)) {
            addToStringList(result, substr);
            hashSetInsert(seen, substr);
        }

        free(substr);
        left--;
        right++;
    }
}

// === Main API ===
StringList getUniquePalindromicSubstrings(char *s) {
    StringList result;
    initStringList(&result);
    HashSet seen;
    initHashSet(&seen);

    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        expandAndCollectUnique(s, i, i, &result, &seen);       // odd
        expandAndCollectUnique(s, i, i + 1, &result, &seen);   // even
    }

    freeHashSet(&seen);
    return result;
}

int cmpStr(const void *a, const void *b) {
    const char *sa = *(const char **)a;
    const char *sb = *(const char **)b;
    return strcmp(sa, sb);
}

// === Test ===
int main() {
    char s[] = "abbaeae";
    StringList uniquePalindromes = getUniquePalindromicSubstrings(s);

    // Sort alphabetically
    qsort(uniquePalindromes.items, uniquePalindromes.size, sizeof(char *), cmpStr);

    printf("Unique palindromic substrings (%d):\n", uniquePalindromes.size);
    for (int i = 0; i < uniquePalindromes.size; i++) {
        printf("%s\n", uniquePalindromes.items[i]);
    }

    freeStringList(&uniquePalindromes);
    return 0;
}