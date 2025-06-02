// Insert Delete GetRandom O(1) requires designing a data structure that supports:

// insert(val) – Inserts an item if it’s not present.

// remove(val) – Removes an item if present.

// getRandom() – Returns a random element. Each element must have an equal probability.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define INIT_CAPACITY   128
#define HASH_SIZE       4096

typedef struct{
    int key;
    int value;
    bool occupied;
} HashEntry;

typedef struct{
    int *arr;
    int size;
    int capacity;
    HashEntry *hashTable;
} RandomizedSet;

unsigned int hash(int key){
    return (unsigned int) key % HASH_SIZE;
}

// create set
RandomizedSet* randomizedSetCreate(){
    RandomizedSet *set = malloc(sizeof(RandomizedSet));
    set->arr = malloc(INIT_CAPACITY * sizeof(int));
    set->size = 0;
    set->capacity = INIT_CAPACITY;
    set->hashTable = calloc(HASH_SIZE, sizeof(HashEntry));
    return set;
}

// find index in hash table using linear probing
int hashFind(RandomizedSet *set, int key, bool *found){
    unsigned int idx = hash(key);
    for(int i = 0; i < HASH_SIZE; i++){
        int probe = (idx + 1) % HASH_SIZE;
        HashEntry *entry = &set->hashTable[probe];
        if(!entry->occupied){
            *found = false;
            return probe;
        }
        if(entry->occupied && entry->key == key){
            *found = true;
            return probe;
        }
    }
    *found = false;
    return -1;
}

// insert value
bool randomizedSetInsert(RandomizedSet *set, int val){
    bool found;
    int idx = hashFind(set, val, &found);
    if(found) return false;

    // append to array
    if(set->size == set->capacity){
        set->capacity *= 2;
        set->arr = realloc(set->arr, set->capacity * sizeof(int));
    }
    set->arr[set->size] = val;

    // add to hash map
    set->hashTable[idx].key = val;
    set->hashTable[idx].occupied = true;
    set->hashTable[idx].value = set->size;

    set->size++;
    return true;
}

bool randomizedSetRemove(RandomizedSet *set, int val){
    bool found;
    int idx = hashFind(set, val, &found);
    if(!found) return false;

    int removeIdx = set->hashTable[idx].value;
    int lastVal = set->arr[set->size - 1];

    // move last element into the place of the one being removed
    set->arr[removeIdx] = lastVal;

    // update hash map for last element
    bool dummy;
    int lastIdx = hashFind(set, lastVal, &dummy);
    set->hashTable[lastIdx].value = removeIdx;

    // mark removed
    set->hashTable[idx].occupied = false;
    set->size--;
    return true;
}

// Get random value
int randomizedSetGetRandom(RandomizedSet* set) {
    if (set->size == 0) return -1;
    int randIdx = rand() % set->size;
    return set->arr[randIdx];
}

// Free memory
void randomizedSetFree(RandomizedSet* set) {
    free(set->arr);
    free(set->hashTable);
    free(set);
}

int main() {
    RandomizedSet *set = randomizedSetCreate();

    printf("Insert 1: %d\n", randomizedSetInsert(set, 1)); // true
    printf("Remove 2: %d\n", randomizedSetRemove(set, 2)); // false
    printf("Insert 2: %d\n", randomizedSetInsert(set, 2)); // true
    printf("Random: %d\n", randomizedSetGetRandom(set));   // 1 or 2
    printf("Remove 1: %d\n", randomizedSetRemove(set, 1)); // true
    printf("Insert 2: %d\n", randomizedSetInsert(set, 2)); // false
    printf("Random: %d\n", randomizedSetGetRandom(set));   // 2

    randomizedSetFree(set);
    return 0;
}