#include <stdio.h>

typedef struct
{
    int size;
    int top;
    int *arr;
} Stack;

int isEmpty(Stack *ptr)
{
    if (ptr->top == -1)
    {
        return -1;
    }
    return 0;
}

int isFull(Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return -1;
    }
    return 0;
}

void push(Stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int peek(Stack *s, int i)
{
    int arrayIndex = s->top - i + 1;
    if (arrayIndex < 0)
    {
        printf("Not a Valid position");
        return -1;
    }
    else
    {
        return s->arr[arrayIndex];
    }
}
void pop(Stack *ptr)
{
    if (isFull(ptr))
    {
        printf("Stack underflow");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
    }
}

int stackTop(Stack *s)
{
    return s->arr[s->top];
}
int stackBottom(Stack *s)
{
    return s->arr[0];
}
int main()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    // s.size = 80;
    // s.top = 99;
    // s.arr = (int *)malloc(s.size * sizeof(int));

    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    push(s, 5);
    push(s, 13);
    printf("%d\n", peek(s, 1));
    printf("is Stack empty: %d", isEmpty(s));
    return 0;
}