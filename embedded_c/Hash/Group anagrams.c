#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS           100
#define MAX_LEN             100
#define TABLE_SIZE          211         // prime number for better distribution 

// struct for linked list of anagrams
typedef struct WordNode{
    char *word;
    struct WordNode *next;
} WordNode;

// hash table entry
typedef struct HashEntry{
    char *sortedKey;    // sorted string used as key
    WordNode *words;    // linked list of anagram words
    bool in_use;
} HashEntry;

HashEntry hashTable[TABLE_SIZE];

// simple string sort (bubble sort)
char *sortString(const char *s)
{
    char *sorted = strdup(s);
    int len = strlen(sorted);
    for(int i = 0; i < len - 1; i++)
    {
        for(int j = i + 1; j < len; j++)
        {
            if(sorted[i] > sorted[j])
            {
                char tmp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = tmp;
            }
        }
    }
    return sorted;
}

// djb2 hash function
unsigned int hash(const char *str)
{
    unsigned int hash = 5381;
    int c;
    while((c = *str++))
    {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % TABLE_SIZE;
}

void addWord(const char *word)
{
    char *key = sortString(word);
    unsigned int idx = hash(key);

    // linear probing
    while(hashTable[idx].in_use)
    {
        if(strcmp(hashTable[idx].sortedKey, key) == 0)
        {
            break;
        }
        idx = (idx + 1) % TABLE_SIZE;
    }

    if(!hashTable[idx].in_use)
    {
        hashTable[idx].sortedKey = key;
        hashTable[idx].words = NULL;
        hashTable[idx].in_use = true;
    }
    else
    {
        free(key); // already exists, discard new key
    }

    // insert key to the front of the linked list
    WordNode *node = malloc(sizeof(WordNode));
    node->word = strdup(word);
    node->next = hashTable[idx].words;
    hashTable[idx].words = node;
}

void printGroups()
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(hashTable[i].in_use)
        {
            printf("[ ");
            for(WordNode *node = hashTable[i].words; node; node = node->next)
            {
                printf("\"%s\" ", node->word);
            }
            printf("]\n");
        }
    }
}

void freeTable()
{
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if(hashTable[i].in_use)
        {
            free(hashTable[i].sortedKey);
            WordNode *node = hashTable[i].words;
            while(node)
            {
                WordNode *tmp = node;
                node = node->next;
                free(tmp->word);
                free(tmp);
            }
        }
    }
}

int main()
{
    const char *words[] = {"ear", "tea", "tan", "ate", "nat", "bat"};
    int n = sizeof(words) / sizeof(words[0]);

    for(int i = 0; i < n; i++)
    {
        addWord(words[i]);
    }

    printGroups();
    freeTable();
    return 0;
}