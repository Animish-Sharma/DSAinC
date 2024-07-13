#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversalLinked(struct Node *head)
{
    struct Node *p = head;

    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
}

struct Node *addToFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

int main()
{
    struct Node *head, *second, *third;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 3;
    head->next = second;

    second->data = 5;
    second->next = third;

    third->data = 7;
    third->next = head;

    addToFirst(third, 1);

    traversalLinked(head);
    return 0;
}