#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

void push(int x)
{
    if (top >= MAX - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        stack[++top] = x;
        printf("%d pushed\n", x);
    }
}

void pop()
{
    if (top < 0)
    {
        printf("Stack underflow\n");
    }
    else
    {
        printf("%d popped\n", stack[top--]);
    }
}

void display()
{
    if (top < 0)
    {
        printf("Stack empty\n");
    }
    else
    {
        printf("Stack: ");
        for (int i = 0; i <= top; i++)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main()
{
    int choice, x;
    while (1)
    {
        printf("\n1.Push \n2.Pop \n3.Display \n4.Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}
