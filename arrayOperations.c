#include <stdio.h>

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int indInsertion(int arr[], int size, int element, int capacity, int index)
{
    if (index >= capacity)
    {
        printf("Overflow\n");
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        /* code */
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}
void indDelete(int arr[], int size, int index)
{
    for (int i = index; i < size; i++)
    {
        /* code */
        arr[i] = arr[i + 1];
    }
}

int main()
{
    int arr[100] = {3, 5, 1, 7, 2, 8};
    int size = 6, element = 45, index = 3;
    display(arr, size);
    indDelete(arr, size, 2);
    size -= 1;
    display(arr, size);
    return 0;
}