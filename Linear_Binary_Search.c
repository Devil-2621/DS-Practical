#include <stdio.h>

// Linear Search Function
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Binary Search Function (requires sorted array)
int binarySearch(int arr[], int left, int right, int key)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[100], n, key, choice;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    printf("\n1. Linear Search\n2. Binary Search\nEnter your choice (1 or 2): ");
    scanf("%d", &choice);

    int result;
    switch (choice)
    {
    case 1:
        result = linearSearch(arr, n, key);
        break;
    case 2:
        result = binarySearch(arr, 0, n - 1, key);
        break;
    default:
        printf("Invalid choice!\n");
        return 1;
    }

    if (result == -1)
        printf("\nElement not found!");
    else
        printf("\nElement found at index: %d", result);

    return 0;
}