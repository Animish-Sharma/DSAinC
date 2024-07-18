#include <stdio.h>

struct circularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct circularQueue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct circularQueue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct circularQueue *q, int val)
{
    if (isFull(q))
    {
        printf("Stack Overflow");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
    }
}
void dequeue(struct circularQueue *q, int val)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("Stack Underflow");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
    }
}

int main()
{
    struct circularQueue q;
    q.size = 4;
    q.f, q.r = 0;
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