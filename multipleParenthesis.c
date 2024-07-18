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

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow");
        return "0";
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int parenthesisMatch(char *exp)
{
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_char;

    for (int i = 0; exp[i] != "\0"; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')', exp[i] == '}', exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            popped_char = pop(sp);
            if (!match(stackTop(sp), popped_char))
            {
                return 0;
            }
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    return 0;
}

int match(char a, char b)
{
    if (a == "(" && b == ")")
    {
        return 1;
    }
    else if (a == "{" && b == "}")
    {
        return 1;
    }
    else if (a == "[" && b == "]")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char stackTop(struct stack *s)
{
    return s->arr[s->top];
}
int main()
{
    char *exp = "[8}*(9)";
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