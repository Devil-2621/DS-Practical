#include <stdio.h>
#include <stdlib.h>

// Structure for doubly linked list node
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Global pointers for head and tail
struct Node *head = NULL;
struct Node *tail = NULL;

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// FIFO insertion (at end)
void insertFIFO(int value)
{
    struct Node *newNode = createNode(value);

    if (head == NULL)
    {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

// LIFO insertion (at beginning)
void insertLIFO(int value)
{
    struct Node *newNode = createNode(value);

    if (head == NULL)
    {
        head = tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Delete from front (for FIFO)
void deleteFIFO()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Delete from head (for LIFO)
void deleteLIFO()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    else
        tail = NULL;

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Display the list
void display()
{
    struct Node *current = head;
    if (current == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("List elements: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    // FIFO example
    printf("FIFO Operations:\n");
    insertFIFO(10);
    insertFIFO(20);
    insertFIFO(30);
    display();
    deleteFIFO();
    display();

    // Clear list
    while (head != NULL)
        deleteFIFO();

    printf("\nLIFO Operations:\n");
    insertLIFO(10);
    insertLIFO(20);
    insertLIFO(30);
    display();
    deleteLIFO();
    display();

    // Clear list
    while (head != NULL)
        deleteLIFO();

    return 0;
}