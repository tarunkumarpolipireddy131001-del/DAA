#include <stdio.h>
void heapSort(int arr[], int n)
{
    int i, left, right, largest, temp;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        left = 2 * i + 1;
        right = 2 * i + 2;
        largest = i;
        
        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;
        if (largest != i)
        {
            temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
        }
    }
    for (i = n - 1; i > 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        left = 1;
        right = 2;
        largest = 0;

        if (left < i && arr[left] > arr[largest])
            largest = left;

        if (right < i && arr[right] > arr[largest])
            largest = right;

        if (largest != 0)
        {
            temp = arr[0];
            arr[0] = arr[largest];
            arr[largest] = temp;
        }
    }
}

int main()
{
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Original array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    heapSort(arr, n);
    printf("\nSorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
