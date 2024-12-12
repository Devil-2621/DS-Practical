#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
char stack[MAX];
int top = -1;

// Basic stack operations
void push(char x) { stack[++top] = x; }
char pop() { return stack[top--]; }

// Returns operator priority
int priority(char x)
{
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

// Convert infix to postfix
void infixToPostfix(char infix[], char postfix[])
{
    int i, j;
    for (i = 0, j = 0; infix[i] != '\0'; i++)
    {
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (top >= 0 && stack[top] != '(')
                postfix[j++] = pop();
            if (top >= 0)
                pop(); // Remove '('
        }
        else
        {
            while (top >= 0 && priority(stack[top]) >= priority(infix[i]))
                postfix[j++] = pop();
            push(infix[i]);
        }
    }
    while (top >= 0)
        postfix[j++] = pop();
    postfix[j] = '\0';
}

void strrev(char *str)
{
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infixToPrefix(char infix[], char prefix[])
{
    int i, j;
    strrev(infix);
    for (i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }
    infixToPostfix(infix, prefix);
    strrev(prefix);
}

int main()
{
    char infix[MAX], postfix[MAX];
    char prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);

    infixToPrefix(infix, prefix);
    printf("Prefix: %s\n", prefix);
    return 0;
}