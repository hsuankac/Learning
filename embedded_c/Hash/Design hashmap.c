#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TABLE_SIZE              101    // prime number for better hash distribution

// hash map entry
typedef struct Entry{
    char *key;
    int value;
    struct Entry *next;
} Entry;

// hash map
typedef struct{
    Entry **buckets;
} HashMap;

// hash function, djb2
unsigned int hash(const char *key){
    unsigned long hash = 5381;
    int c;
    while((c = *key++)){
        hash = ((hash << 5) + hash) + c;
    }
    return hash % TABLE_SIZE;
}

HashMap *createHashMap(){
    HashMap *map = malloc(sizeof(HashMap));
    map->buckets = calloc(TABLE_SIZE, sizeof(Entry*));
    return map;
}

void put(HashMap *map, const char *key, int value){
    unsigned int idx = hash(key);
    Entry *curr = map->buckets[idx];

    // update if key already exists
    while(curr){
        if(strcmp(curr->key, key) == 0){
            curr->value = value;
            return;
        }
        curr = curr->next;
    }

    // add new entry
    Entry *newEntry = malloc(sizeof(Entry));
    newEntry->key = strdup(key);
    newEntry->value = value;
    newEntry->next = map->buckets[idx];
    map->buckets[idx] = newEntry;
}

// get value by key
int get(HashMap *map, const char *key, int *found){
    unsigned int idx = hash(key);
    Entry *curr = map->buckets[idx];
    while(curr){
        if(strcmp(curr->key, key) == 0){
            *found = 1;
            return curr->value;
        }
        curr = curr->next;
    }
    *found = 0;
    return 0;
}

// remove key
void removeKey(HashMap *map, const char *key){
    unsigned int idx = hash(key);
    Entry *curr = map->buckets[idx];
    Entry *prev = NULL;

    while(curr){
        if(strcmp(curr->key, key) == 0){
            if(prev)
                prev->next = curr->next;
            else
                map->buckets[idx] = curr->next;
            free(curr->key);
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void freeHashMap(HashMap *map){
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        Entry *curr = map->buckets[i];
        while(curr){
            Entry *tmp = curr;
            curr = curr->next;
            free(tmp->key);
            free(tmp);
        }
    }
    free(map->buckets);
    free(map);
}

int main()
{
    HashMap *map = createHashMap();

    put(map, "apple", 10);
    put(map, "banana", 20);
    put(map, "orange", 30);

    int found;
    int value = get(map, "banana", &found);
    if (found)
        printf("banana: %d\n", value);
    else
        printf("banana not found\n");

    removeKey(map, "banana");

    value = get(map, "banana", &found);
    if (!found)
        printf("banana has been removed\n");

    freeHashMap(map);
    return 0;
}