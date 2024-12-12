#include <stdio.h>
#define MAX 5

void insertFront(int *, int *, int *, int);
void insertRear(int *, int *, int *, int);
void deleteFront(int *, int *, int *);
void deleteRear(int *, int *, int *);
void display(int *, int *, int *);

int main()
{
    int deque[MAX];
    int front = -1, rear = -1, choice, value;

    printf("\n=== Double Ended Queue Operations ===\n");
    printf("1. Input Restricted Deque\n");
    printf("2. Output Restricted Deque\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1)
    { // Input Restricted
        while (1)
        {
            printf("\n1. Insert at Rear\n2. Delete from Front");
            printf("\n3. Delete from Rear\n4. Display\n5. Exit");
            printf("\nEnter choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(deque, &front, &rear, value);
                break;
            case 2:
                deleteFront(deque, &front, &rear);
                break;
            case 3:
                deleteRear(deque, &front, &rear);
                break;
            case 4:
                display(deque, &front, &rear);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
            }
        }
    }
    else if (choice == 2)
    { // Output Restricted
        while (1)
        {
            printf("\n1. Insert at Front\n2. Insert at Rear");
            printf("\n3. Delete from Front\n4. Display\n5. Exit");
            printf("\nEnter choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(deque, &front, &rear, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(deque, &front, &rear, value);
                break;
            case 3:
                deleteFront(deque, &front, &rear);
                break;
            case 4:
                display(deque, &front, &rear);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
            }
        }
    }
    return 0;
}

void insertFront(int *deque, int *front, int *rear, int value)
{
    if ((*front == 0 && *rear == MAX - 1) || (*front == *rear + 1))
    {
        printf("Queue is full!\n");
        return;
    }
    if (*front == -1)
    {
        *front = *rear = 0;
    }
    else if (*front == 0)
    {
        *front = MAX - 1;
    }
    else
    {
        (*front)--;
    }
    deque[*front] = value;
}

void insertRear(int *deque, int *front, int *rear, int value)
{
    if ((*front == 0 && *rear == MAX - 1) || (*front == *rear + 1))
    {
        printf("Queue is full!\n");
        return;
    }
    if (*front == -1)
    {
        *front = *rear = 0;
    }
    else if (*rear == MAX - 1)
    {
        *rear = 0;
    }
    else
    {
        (*rear)++;
    }
    deque[*rear] = value;
}

void deleteFront(int *deque, int *front, int *rear)
{
    if (*front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Deleted element: %d\n", deque[*front]);
    if (*front == *rear)
    {
        *front = *rear = -1;
    }
    else if (*front == MAX - 1)
    {
        *front = 0;
    }
    else
    {
        (*front)++;
    }
}

void deleteRear(int *deque, int *front, int *rear)
{
    if (*front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Deleted element: %d\n", deque[*rear]);
    if (*front == *rear)
    {
        *front = *rear = -1;
    }
    else if (*rear == 0)
    {
        *rear = MAX - 1;
    }
    else
    {
        (*rear)--;
    }
}

void display(int *deque, int *front, int *rear)
{
    if (*front == -1)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    if (*rear >= *front)
    {
        for (int i = *front; i <= *rear; i++)
            printf("%d ", deque[i]);
    }
    else
    {
        for (int i = *front; i < MAX; i++)
            printf("%d ", deque[i]);
        for (int i = 0; i <= *rear; i++)
            printf("%d ", deque[i]);
    }
    printf("\n");
}