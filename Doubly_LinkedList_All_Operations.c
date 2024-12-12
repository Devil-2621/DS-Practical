#include <stdio.h>
#include <stdlib.h>

// Structure for doubly linked list node
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function prototypes
struct Node *createNode(int data);
void insertAtEnd(struct Node **head, int data);
void deleteNode(struct Node **head, int key);
struct Node *search(struct Node *head, int key);
void reverse(struct Node **head);
void display(struct Node *head);

// Create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the end
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Delete a node with given key
void deleteNode(struct Node **head, int key)
{
    if (*head == NULL)
        return;

    struct Node *current = *head;

    // If head node itself holds the key
    if (current->data == key)
    {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(current);
        return;
    }

    while (current != NULL && current->data != key)
        current = current->next;

    if (current == NULL)
        return;

    current->prev->next = current->next;
    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
}

// Search for a node with given key
struct Node *search(struct Node *head, int key)
{
    struct Node *current = head;
    while (current != NULL)
    {
        if (current->data == key)
            return current;
        current = current->next;
    }
    return NULL;
}

// Reverse the linked list
void reverse(struct Node **head)
{
    struct Node *temp = NULL;
    struct Node *current = *head;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        *head = temp->prev;
}

// Display the linked list
void display(struct Node *head)
{
    struct Node *temp = head;
    printf("\nList: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main()
{
    struct Node *head = NULL;
    int choice, data, key;

    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Reverse\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;

        case 2:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            deleteNode(&head, key);
            break;

        case 3:
            printf("Enter key to search: ");
            scanf("%d", &key);
            struct Node *result = search(head, key);
            if (result != NULL)
                printf("Element %d found\n", key);
            else
                printf("Element not found\n");
            break;

        case 4:
            reverse(&head);
            printf("List reversed\n");
            break;

        case 5:
            display(head);
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}