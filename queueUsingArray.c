#include <stdio.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("Stack Overflow");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}
void dequeue(struct queue *q, int val)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("Stack Underflow");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
}

int main()
{
    struct queue q;
    q.size = 100;
    q.f, q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    enqueue(&q, 4);
    enqueue(&q, 24);
    enqueue(&q, 42);
    if (isEmpty(&q))
    {
        printf("Queue is Empty");
    }
    return 0;
}