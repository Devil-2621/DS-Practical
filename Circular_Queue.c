#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert()
{
    int element;
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("\nQueue is full!");
        return;
    }
    printf("\nEnter element to insert: ");
    scanf("%d", &element);

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = element;
    printf("Element inserted successfully!");
}

void delete()
{
    if (front == -1)
    {
        printf("\nQueue is empty!");
        return;
    }
    printf("\nDeleted element: %d", queue[front]);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void display()
{
    if (front == -1)
    {
        printf("\nQueue is empty!");
        return;
    }
    printf("\nQueue elements: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    else
    {
        for (int i = front; i < MAX; i++)
        {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n\n1. Insert\n2. Delete\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nExiting...");
            return 0;
        default:
            printf("\nInvalid choice!");
        }
    }
    return 0;
}