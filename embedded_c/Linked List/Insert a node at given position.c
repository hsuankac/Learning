// C program for insertion in a single linked
// list at a specified position
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int x);

// Function to insert a Node at the required position
struct Node *insertPos(struct Node *head, int pos, int data) {

    // return if invalid input
    if (pos < 1)
        return head;

    // Head will change if pos=1
    if (pos == 1) {
        struct Node *newNode = createNode(data);
        newNode->next = head;
        return newNode;
    }

    struct Node *curr = head;

    // Traverse to the node that will be
    // present just before the new node
    for (int i = 1; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }
    
    // if position is greater than
    // number of nodes
    if (curr == NULL) 
        return head;
        
    struct Node *newNode = createNode(data);

    // Update the next pointers
    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

void printList(struct Node *head) {
    struct Node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

struct Node *createNode(int x) {
    struct Node *new_node = 
      (struct Node *)malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->next = NULL;
    return new_node;
}

int main() {

    // Creating the list 3->5->8->10
    struct Node *head = createNode(3);
    head->next = createNode(5);
    head->next->next = createNode(8);
    head->next->next->next = createNode(10);

    int data = 12, pos = 3;
    head = insertPos(head, pos, data);
    printList(head);

    return 0;
}