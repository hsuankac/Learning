#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf(" %d", node->data);
        node = node->next;
    }
}

// Given the head of a list, reverse the list and return the
// head of reversed list
struct Node* reverseList(struct Node* head) {

    // Initialize three pointers: curr, prev and next
    struct Node *curr = head, *prev = NULL, *next;

    // Traverse all the nodes of Linked List
    while (curr != NULL) {

        // Store next
        next = curr->next;

        // Reverse current node's next pointer
        curr->next = prev;

        // Move pointers one position ahead
        prev = curr;
        curr = next;
    }

    // Return the head of reversed linked list
    return prev;
}

/* Recursive approach*/
// // Given the head of a list, reverse the list and 
// // return the head of reversed list
// struct Node* reverseList(struct Node* head) {
//     if (head == NULL || head->next == NULL)
//         return head;

//     // reverse the rest of linked list and put 
// 	// the first element at the end
//     struct Node* rest = reverseList(head->next);

//     // Make the current head as last node of 
// 	// remaining linked list
//     head->next->next = head;

//     // Update next of current head to NULL
//     head->next = NULL;

//     // Return the reversed linked list
//     return rest;
// }

/* Reverse a linked list using stack*/
// // Function to reverse the linked list
// struct Node* reverseList(struct Node* head) {
  
//     // Create a stack to store the nodes
//     struct Node* stack[100000];
//     int top = -1;
    
//     struct Node* temp = head;
    
//     // Push all nodes except the last node into stack
//     while (temp != NULL) {
//         stack[++top] = temp;
//         temp = temp->next;
//     }
    
//     // Make the last node as new head of the linked list
//     if (top >= 0) {
//         head = stack[top];
//         temp = head;
        
//         // Pop all the nodes and append to the linked list
//         while (top > 0) {
          	
//           	// append the top value of stack in list and 
//           	// pop the top value by decrementing top by 1
//             temp->next = stack[--top];
          
//           	// move to the next node in the list
//             temp = temp->next;
//         }
        
//         // Update the next pointer of last node of stack to NULL
//         temp->next = NULL;
//     }
    
//     return head;
// }

int main() {

    // Create a hard-coded linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Given Linked list:");
    printList(head);

    head = reverseList(head);

    printf("\nReversed Linked List:");
    printList(head);

    return 0;
}