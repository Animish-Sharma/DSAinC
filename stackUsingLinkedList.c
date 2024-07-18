#include <stdio.h>
struct Node
{
    int data;
    struct Node *next;
};

void transverseList(struct Node *head)
{
    do
    {
        printf("%d ", head->data);
        head = head->next;
    } while (head != NULL);
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("List is full");
        return 1;
    }
    return 0;
}

struct Node *push(struct Node *top, int data)
{

    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->next = top;
    top = p;

    return top;
}

struct Node *pop(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack Underflow");
    }
    else
    {
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        p = top;
        top = top->next;
        free(p);
    }
    return top;
}

int peek(struct Node *top, int index)
{
    int i = 0;
    while (index - 1 > i)
    {
        top = top->next;
        i++;
    }
    int d = top->data;
    printf("Element at index %d is %d \n", index, d);
    return 0;
}

int stackTop(struct Node *top)
{
    int s = top->data;
    return s;
}

int stackBottom(struct Node *top)
{
    while (top->next != NULL)
    {
        top = top->next;
    }
    int s = top->data;
    printf("Last Element is %d\n", s);
    return s;
}

int main()
{
    struct Node *top = NULL;

    top = push(top, 1);
    top = push(top, 3);
    top = push(top, 5);
    top = push(top, 7);
    peek(top, 1);
    stackTop(top);
    stackBottom(top);
    transverseList(top);

    return 0;
}