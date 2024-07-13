#include <stdio.h>

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0, high = size - 1;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (element == arr[mid])
        {
            return mid;
        }
        if (element > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    int size = 11;
    int searchIndex = binarySearch(arr, size, 13);
    printf("Element %d found at index %i", 13, searchIndex);
    return 0;
}