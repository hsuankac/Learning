#include <stdio.h>
#include <string.h>

#define WINDOW_SIZE 300

typedef struct {
    int times[WINDOW_SIZE];
    int hits[WINDOW_SIZE];
} HitCounter;

/**
 * Initialize your data structure.
 */
void hitCounterInit(HitCounter* obj) {
    memset(obj->times, 0, sizeof(obj->times));
    memset(obj->hits, 0, sizeof(obj->hits));
}

/**
 * Record a hit.
 */
void hit(HitCounter* obj, int timestamp) {
    int index = timestamp % WINDOW_SIZE;
    if (obj->times[index] != timestamp) {
        // New timestamp at this bucket, reset count
        obj->times[index] = timestamp;
        obj->hits[index] = 1;
    } else {
        obj->hits[index]++;
    }
}

/**
 * Return number of hits in past 300 seconds.
 */
int getHits(HitCounter* obj, int timestamp) {
    int total = 0;
    for (int i = 0; i < WINDOW_SIZE; i++) {
        if (timestamp - obj->times[i] < WINDOW_SIZE) {
            total += obj->hits[i];
        }
    }
    return total;
}

int main() {
    HitCounter counter;
    hitCounterInit(&counter);

    hit(&counter, 1);
    hit(&counter, 1);
    hit(&counter, 2);
    hit(&counter, 300);
    printf("Hits at t=300: %d\n", getHits(&counter, 300));  // Should be 4

    hit(&counter, 301);
    printf("Hits at t=301: %d\n", getHits(&counter, 301));  // Should be 3 (1,2,301)

    return 0;
}