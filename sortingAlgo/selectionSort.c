#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    int A[] = {5, 1, 6, 2, 9, 10};
    printArray(A, 6);
    return 0;
}