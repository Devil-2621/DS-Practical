#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function prototypes
struct Node *createNode(int);
void insertAtBeginning(struct Node **, int);
void deleteNode(struct Node **, int);
struct Node *searchNode(struct Node *, int);
void reverseList(struct Node **);
void displayList(struct Node *);

// Create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Delete a node with given value
void deleteNode(struct Node **head, int key)
{
    struct Node *temp = *head, *prev = NULL;

    if (temp != NULL && temp->data == key)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

// Search for a node
struct Node *searchNode(struct Node *head, int key)
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
void reverseList(struct Node **head)
{
    struct Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Display the linked list
void displayList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

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
            insertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &key);
            deleteNode(&head, key);
            break;
        case 3:
            printf("Enter value to search: ");
            scanf("%d", &key);
            struct Node *result = searchNode(head, key);
            if (result != NULL)
                printf("Element %d found\n", key);
            else
                printf("Element %d not found\n", key);
            break;
        case 4:
            reverseList(&head);
            printf("List reversed\n");
            break;
        case 5:
            displayList(head);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}