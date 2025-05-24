#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

// Function to segregate even and odd nodes 
// and return the head of the new list
struct Node* segregateEvenOdd(struct Node* head) {
  
    // Result list to hold even nodes
    struct Node* resStart = NULL;
    struct Node* resEnd = NULL;

    // Pointers for the original list
    struct Node* curr = head;
    struct Node* prev = NULL;

    // Move all even nodes from original to result
    while (curr != NULL) {
      
        // If current node is even
        if (curr->data % 2 == 0) {
          
            // Remove the current even node
            // from the original list
            if (prev != NULL) {
                prev->next = curr->next;
            } else {
                // If the even node is at the head
                head = curr->next;
            }

            // Add the current even node to the result list
            if (resStart == NULL) {
                resStart = curr;
                resEnd = resStart;
            } else {
                resEnd->next = curr;
                resEnd = resEnd->next;
            }

            curr = curr->next;
        } else {
            // If the node is odd, just move to the next
            prev = curr;
            curr = curr->next;
        }
    }

    // If there are no even nodes, return the original list
    if (resStart == NULL) {
        return head;
    }

    // Append the remaining original list
    // (odd nodes) to the result list
    resEnd->next = head;

    // Return the result list (starting with even nodes)
    return resStart;
}

/*Maintaining start and end method*/
// // Function to segregate even and odd nodes 
// // and return the head of the new list.
// struct Node* segregateEvenOdd(struct Node* head) {
  
//     // We create dummy nodes to avoid extra 
//     // condition checks in the while loop.
//     struct Node* eStart = newNode(0);
//     struct Node* oStart = newNode(0);
    
//     // Pointers to the end of the even and odd lists
//     struct Node* eEnd = eStart;
//     struct Node* oEnd = oStart;

//     // Node to traverse the list
//     struct Node* curr = head;

//     while (curr != NULL) {
//         int val = curr->data;

//         // If current value is even, add it to the even list
//         if (val % 2 == 0) {
//             eEnd->next = curr;
//             eEnd = eEnd->next;
//         } else { // Else to the odd list
//             oEnd->next = curr;
//             oEnd = oEnd->next;
//         }

//         // Move to the next node
//         curr = curr->next;
//     }

//     // Terminate the odd list
//     oEnd->next = NULL;

//     // Combine even and odd lists
//     eEnd->next = oStart->next;

//     // Return the new head of the combined list (even head)
//     struct Node* newHead = eStart->next;

//     // Clean up dummy nodes
//     free(eStart);
//     free(oStart);

//     return newHead;
// }

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    // Create a sample linked list: 0->1->4->6->9->10->11
    struct Node* head = newNode(0);
    head->next = newNode(1);
    head->next->next = newNode(4);
    head->next->next->next = newNode(6);
    head->next->next->next->next = newNode(9);
    head->next->next->next->next->next = newNode(10);
    head->next->next->next->next->next->next = newNode(11);

    printf("Original Linked list: ");
    printList(head);

    head = segregateEvenOdd(head);

    printf("Modified Linked list: ");
    printList(head);

    return 0;
}