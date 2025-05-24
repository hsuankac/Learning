#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to delete the Nth node from the end
Node* deleteNthFromEnd(Node* head, int n) {
    Node dummy;
    dummy.next = head;

    Node* fast = &dummy;
    Node* slow = &dummy;

    // Move fast pointer n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        if (fast == NULL) return head; // n is longer than list
        fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Delete the node
    Node* temp = slow->next;
    if (temp != NULL) {
        slow->next = temp->next;
        free(temp);
    }

    return dummy.next;
}

// Helper functions to test the code
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Sample usage
int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original list:\n");
    printList(head);

    int n = 5;
    head = deleteNthFromEnd(head, n);

    printf("After deleting %dth node from the end:\n", n);
    printList(head);

    return 0;
}
