// C program for sorted insert in 
// circular linked list

#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node 
// in the list in a sorted way
struct Node* sortedInsert(struct Node* head, int data) 
{
    // Create the new node with the given data
    struct Node* newNode = createNode(data);

    // if linked list is empty
    if(head == NULL)
    {
        // point to itself to make it circular
        newNode->next = newNode;
        head = newNode;
        return head;
    }

    struct Node* curr = head;
    struct Node* nextToCurr = head->next;

    // insert at the beginning if data is less than or equal to head's data
    if(data <= head->data)
    {
        struct Node* lastNode = head;
        while(lastNode->next != head){
            // find the last node
            lastNode = lastNode->next;
        }
        // set new node's next to head
        newNode->next = head;
        // update last node's next to new node
        lastNode->next = newNode;
        // update head to new node
        head = newNode;
        return head;
    }

    // insert in the middle of the list
    while(curr->next != head)
    {
        if(curr->data < data && nextToCurr->data >= data)
        {
            // set new node's next to current's next
            newNode->next = curr->next;
            curr->next = newNode;
            return head;
        }else{
            // move to the next node
            curr = curr->next;
            nextToCurr = nextToCurr->next;
        }
    }

    // insert at the end of the list
    newNode->next = head;
    curr->next = newNode;
    return head;

}

int main() {
  
    // Create circular linked list: 3->7->9->11->3
    struct Node *head = createNode(3);
    head->next = createNode(7);
    head->next->next = createNode(9);
    head->next->next->next = createNode(11);
    head->next->next->next->next = head;
  
    head = sortedInsert(head, 12);
    struct Node *curr = head;
    
    if (head != NULL) {
        do {
            printf("%d ", curr->data);
            curr = curr->next;
        } while (curr != head);
    }   
    printf("\n");
}