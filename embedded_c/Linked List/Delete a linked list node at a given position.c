// C program to delete a linked list node at a given
// position

#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data)
{
    struct Node* node
        = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to delete a node at a given position
struct Node* deleteNode(struct Node* head, int position)
{
    struct Node* temp = head;
    struct Node* prev = NULL;

    // Base case if linked list is empty
    if (temp == NULL)
        return head;

    // Case 1: Head is to be deleted
    if (position == 1) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Case 2: Node to be deleted is in middle
    // Traverse till given position
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    // If given position is found, delete node
    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }
    else {
        printf("Data not present\n");
    }

    return head;
}

void printList(struct Node* head)
{
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Driver code
int main()
{
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printf("Original list: ");
    printList(head);

    int position = 2;
    head = deleteNode(head, position);

    printf("List after deletion: ");
    printList(head);

    // Cleanup remaining nodes
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}