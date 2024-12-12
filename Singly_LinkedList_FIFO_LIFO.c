#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    return new;
}

void insert(Node **head, int data, int isFIFO)
{
    Node *new = createNode(data);
    if (isFIFO)
    {
        if (!*head)
        {
            *head = new;
            return;
        }
        Node *temp = *head;
        while (temp->next)
            temp = temp->next;
        temp->next = new;
    }
    else
    {
        new->next = *head;
        *head = new;
    }
}

void delete(Node **head)
{
    if (!*head)
    {
        printf("Empty!\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void display(Node *head)
{
    while (head)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    Node *head = NULL;
    int choice, data;

    while (1)
    {
        printf("\n1:FIFO 2:LIFO 3:Delete 4:Display 5:Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 5)
            break;
        if (choice == 3)
            delete (&head);
        else if (choice == 4)
            display(head);
        else if (choice <= 2)
        {
            printf("Data: ");
            scanf("%d", &data);
            insert(&head, data, choice == 1);
        }
    }
    return 0;
}
