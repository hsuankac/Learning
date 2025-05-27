#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int timestamp;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} HitCounter;

// Initialize the hit counter
void hitCounterInit(HitCounter* obj) {
    obj->head = NULL;
    obj->tail = NULL;
    obj->size = 0;
}

// Record a hit at a given timestamp
void hit(HitCounter* obj, int timestamp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->timestamp = timestamp;
    newNode->next = NULL;

    if (obj->tail) {
        obj->tail->next = newNode;
        obj->tail = newNode;
    } else {
        obj->head = obj->tail = newNode;
    }

    obj->size++;
}

// Get number of hits in the past 300 seconds
int getHits(HitCounter* obj, int timestamp) {
    while (obj->head && timestamp - obj->head->timestamp >= 300) {
        Node* temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
        obj->size--;
    }

    if (!obj->head) {
        obj->tail = NULL;
    }

    return obj->size;
}

// Cleanup memory
void hitCounterFree(HitCounter* obj) {
    while (obj->head) {
        Node* temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    }
    obj->tail = NULL;
    obj->size = 0;
}

int main() {
    HitCounter counter;
    hitCounterInit(&counter);

    hit(&counter, 1);
    hit(&counter, 1);
    hit(&counter, 2);
    hit(&counter, 300);
    printf("Hits at t=300: %d\n", getHits(&counter, 300));  // Output: 4

    hit(&counter, 301);
    printf("Hits at t=301: %d\n", getHits(&counter, 301));  // Output: 3

    hitCounterFree(&counter);
    return 0;
}