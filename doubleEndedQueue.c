#include <stdio.h>

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct Queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueueF(struct Queue *q, int val)
{
    q->r++;
    q->arr[q->r] = val;
}
void enqueueR(struct Queue *q, int val)
{
    q->arr[q->r] = val;
    q->f--;
}

int isEmpty(struct Queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int DeQueueR(struct Queue *q)
{
    int val = q->arr[q->r];
    q->r--;
    return val;
}
int DeQueueF(struct Queue *q)
{
    q->f++;
    int val = q->arr[q->f];
    return val;
}

void display(struct Queue *q)
{
    for (int i = 0; i <= q->r; i++)
    {
        printf("Element: %d\n", q->arr[i]);
    }
}

int main()
{
    struct Queue q;
    q.size = 100;
    q.f, q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    enqueueF(&q, 11);
    enqueueF(&q, 13);
    enqueueF(&q, 12);
    enqueueF(&q, 17);
    display(&q);
    if (isEmpty(&q))
    {
        printf("Queue is Empty");
    }
}