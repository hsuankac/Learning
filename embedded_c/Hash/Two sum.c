// Two sum problem implement in C
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE          1000

typedef struct Entry
{
    int key;
    int value;
    struct Entry* next;
} Entry;

typedef struct HashTable
{
    Entry* table[TABLE_SIZE];
} HashTable;

int hash(int key)
{
    if(key < 0) key = -key;
    return key % TABLE_SIZE;
}

HashTable* createTable()
{
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        ht->table[i] = NULL;
    }
    return ht;
}

// Insert key-value pair into the hash table
void insert(HashTable* ht, int key, int value)
{
    int idx = hash(key);
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    newEntry->key = key;
    newEntry->value = value;
    newEntry->next = ht->table[idx];
    ht->table[idx] = newEntry;
}

// Search for a key in the hash table
int find(HashTable* ht, int key, int* outValue) 
{
    int idx = hash(key);
    Entry* entry = ht->table[idx];
    while (entry) {
        if (entry->key == key) {
            *outValue = entry->value;
            return 1;
        }
        entry = entry->next;
    }
    return 0;
}

// Free the hash table
void freeTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) 
    {
        Entry* entry = ht->table[i];
        while (entry) 
        {
            Entry* tmp = entry;
            entry = entry->next;
            free(tmp);
        }
    }
    free(ht);
}

// Two Sum using hash map
int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    HashTable* ht = createTable();

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int foundIndex;

        if (find(ht, complement, &foundIndex)) {
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = foundIndex;
            result[1] = i;
            *returnSize = 2;
            freeTable(ht);
            return result;
        }

        insert(ht, nums[i], i);
    }

    *returnSize = 0;
    freeTable(ht);
    return NULL;
}


// Example usage
int main() {
    int nums[] = {3, 2, 4};
    int target = 6;
    int returnSize;
    int* result = twoSum(nums, 3, target, &returnSize);

    if (result) {
        printf("Indices: %d, %d\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}