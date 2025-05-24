#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

int detectLoop(struct Node* head)
{
    struct Node *slow = head, *fast = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}


int main()
{
    // Create a hard-coded linked list
    struct Node* head = createNode(1);
    head->next = createNode(3);
    head->next->next = createNode(4);

    // Create a loop
    head->next->next->next = head->next;

    if(detectLoop(head)){
        printf("true\n");
    }else{
        printf("false\n");
    }
    return 0;
}