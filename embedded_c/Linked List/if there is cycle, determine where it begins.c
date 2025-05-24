#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
  struct Node* newNode = 
    	(struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to detect a loop in the linked list and 
// return the node where the cycle starts 
// using Floyd’s Cycle-Finding Algorithm
struct Node* findFirstNode(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    
    // Traverse the list
    while (fast != NULL && fast->next != NULL) {
      
        // Move slow pointer by one step
        slow = slow->next;          
      
        // Move fast pointer by two steps
        fast = fast->next->next;    

        // Detect loop
        if (slow == fast) {
          
            // Move slow to head, keep fast at meeting point
            slow = head;
            
            // Move both one step at a time until they meet
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            
            // Return the meeting node, which is the 
          	// start of the loop
            return slow;
        }
    }
    
    // No loop found
    return NULL;
}


int main() {
  
    // Create a linked list: 10 -> 15 -> 4 -> 20
    struct Node* head = createNode(10);
    head->next = createNode(15);
    head->next->next = createNode(4);
    head->next->next->next = createNode(20);

    head->next->next->next->next = head;

    struct Node* loopNode = findFirstNode(head);

   if (loopNode)
        printf("%d\n", loopNode->data);
    else
        printf(-1);

    return 0;
}