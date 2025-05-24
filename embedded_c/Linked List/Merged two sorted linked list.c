#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Merge two sorted lists
Node* mergeSortedLists(Node* l1, Node* l2) {
    Node dummy; // dummy head to simplify edge cases
    Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Append the remaining part
    tail->next = l1 ? l1 : l2;

    return dummy.next;
}

// /* Recursive method*/
// Node* mergeSortedLists(Node* l1, Node* l2) {
//     // Base cases
//     if (l1 == NULL) return l2;
//     if (l2 == NULL) return l1;

//     // Choose the smaller node and recurse
//     if (l1->data <= l2->data) {
//         l1->next = mergeSortedLists(l1->next, l2);
//         return l1;
//     } else {
//         l2->next = mergeSortedLists(l1, l2->next);
//         return l2;
//     }
// }


// Helper to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Print linked list
void printList(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Sample usage
int main() {
    // First sorted list: 1 -> 3 -> 5
    Node* l1 = createNode(1);
    l1->next = createNode(3);
    l1->next->next = createNode(5);

    // Second sorted list: 2 -> 4 -> 6
    Node* l2 = createNode(2);
    l2->next = createNode(4);
    l2->next->next = createNode(6);

    printf("List 1: ");
    printList(l1);
    printf("List 2: ");
    printList(l2);

    Node* merged = mergeSortedLists(l1, l2);
    printf("Merged List: ");
    printList(merged);

    return 0;
}
