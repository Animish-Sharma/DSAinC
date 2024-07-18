#include <stdio.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, char value)
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

void pop(struct stack *ptr)
{
    if (isFull(ptr))
    {
        printf("Stack underflow");
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
    }
}
int parenthesisMatch(char *exp)
{
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != "\0"; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    return 0;
}
int main()
{
    char *exp = "8*(9)";
    if (parenthesisMatch(exp))
    {
        printf("Yes Parenthesis are matching");
    }
    else
    {
        printf("NO, the equation is not balanced");
    }

    return 0;
}