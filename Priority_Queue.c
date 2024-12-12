#include <stdio.h>
#define MAX 100

int pQueue[MAX];
int size = 0;

void insert(int value)
{
    int i;
    if (size == 0)
    {
        pQueue[0] = value;
        size++;
        return;
    }

    for (i = size - 1; i >= 0; i--)
    {
        if (value < pQueue[i])
        {
            pQueue[i + 1] = pQueue[i];
        }
        else
        {
            break;
        }
    }
    pQueue[i + 1] = value;
    size++;
}

int remove_element()
{
    if (size == 0)
    {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = pQueue[size - 1];
    size--;
    return value;
}

void display()
{
    if (size == 0)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Priority Queue: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", pQueue[i]);
    }
    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n1. Insert\n2. Remove\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (size == MAX)
            {
                printf("Queue is full!\n");
                break;
            }
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(value);
            break;

        case 2:
            value = remove_element();
            if (value != -1)
                printf("Removed element: %d\n", value);
            break;

        case 3:
            display();
            break;

        case 4:
            printf("\nExiting...");
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}