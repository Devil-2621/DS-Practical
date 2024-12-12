#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insertNode(struct Node *head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (!head)
    {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = head->next;
    head->next = newNode;
    return head;
}

struct Node *deleteNode(struct Node *head, int value)
{
    if (!head)
        return NULL;
    struct Node *curr = head, *prev = NULL;

    do
    {
        if (curr->data == value)
        {
            if (curr == head)
            {
                if (curr->next == head)
                {
                    free(curr);
                    return NULL;
                }
                head = head->next;
            }
            if (prev)
                prev->next = curr->next;
            else
                head->next = curr->next;
            free(curr);
            return head;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
    return head;
}

void displayList(struct Node *head)
{
    if (!head)
    {
        printf("Empty!\n");
        return;
    }
    struct Node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("head\n");
}

int main()
{
    struct Node *head = NULL;
    int choice, value;

    while (printf("\n1.Insert 2.Delete 3.Display 4.Exit\nChoice: ") && scanf("%d", &choice))
    {
        if (choice == 4)
            break;
        if (choice == 3)
            displayList(head);
        else if (choice == 1 || choice == 2)
        {
            printf("Value: ");
            scanf("%d", &value);
            head = (choice == 1) ? insertNode(head, value) : deleteNode(head, value);
        }
    }
    return 0;
}
