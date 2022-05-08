#include <stdio.h>
#include "Queue.h"
#include "Stack.h"

struct Node *root = NULL;

void createTree()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);
    
    printf("Enter root value");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root -> data = x;
    root -> lchild = root -> rchild = NULL;
    enqueue(&q, root);
    
    while(!isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter left child of %d: ", p -> data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t -> data = x;
            t -> lchild = t -> rchild = NULL;
            p -> lchild = t;
            enqueue(&q, t);
        }
        
        printf("Enter right child of %d: ", p -> data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t -> data = x;
            t -> lchild = t -> rchild = NULL;
            p -> rchild = t;
            enqueue(&q, t);
        }
    }
}

void preorderTraverse(struct Node *p)
{
    if(p)
    {
        printf("%d ", p -> data);
        preorderTraverse(p -> lchild);
        preorderTraverse(p -> rchild);
    }
}

void inorderTraverse(struct Node *p)
{
    if(p)
    {
        inorderTraverse(p -> lchild);
        printf("%d ", p -> data);
        inorderTraverse(p -> rchild);
    }
}

void postorderTraverse(struct Node *p)
{
    if(p)
    {
        postorderTraverse(p -> lchild);
        postorderTraverse(p -> rchild);
        printf("%d ", p -> data);
    }
}

void LevelOrder(struct Node *root)
{
    struct Queue q;
    create(&q, 100);
    printf("%d ", root -> data);
    enqueue(&q, root);
    
    while(!isEmpty(q))
    {
        root = dequeue(&q);
        if(root -> lchild)
        {
            printf("%d ", root -> lchild -> data);
            enqueue(&q, root -> lchild);
        }
        if(root -> rchild)
        {
            printf("%d ", root -> rchild -> data);
            enqueue(&q, root -> rchild);
        }
    }
}

int count(struct Node *root)
{
    if(root)
        return count(root -> lchild) + count(root -> rchild) + 1;
    else
        return 0;
}

int height(struct Node *root)
{
    int x = 0, y = 0;
    if(root == 0)
        return 0;
    x = height(root -> lchild);
    y = height(root -> rchild);
    if(x > y)
        return x + 1;
    else
        return y + 1;
}

void IPreorder(struct Node *p)
{
    struct Stack stk;
    StackCreate(&stk, 100);
    while(p || !isEmptyStack(stk))
    {
        if(p)
        {
            printf("%d ", p -> data);
            push(&stk, p);
            p = p -> lchild;
        }
        else
        {
            p = pop(&stk);
            p = p -> rchild;
        }
    }
}

void IInorder(struct Node *p)
{
    struct Stack stk;
    StackCreate(&stk, 100);
    while(p || !isEmptyStack(stk))
    {
        if(p)
        {
            push(&stk, p);
            p = p -> lchild;
        }
        else
        {
            p = pop(&stk);
            printf("%d ", p -> data);
            p = p -> rchild;
        }
    }
}

int main()
{
    createTree();
    IPreorder(root);
    
    return 0;
}
