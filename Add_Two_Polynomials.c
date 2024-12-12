#include <stdio.h>

struct Poly
{
    int coeff[100];
    int exp;
};

void read(struct Poly *p)
{
    printf("Enter highest degree: ");
    scanf("%d", &p->exp);
    for (int i = 0; i <= p->exp; i++)
    {
        printf("Coefficient for x^%d: ", i);
        scanf("%d", &p->coeff[i]);
    }
}

void add(struct Poly *p1, struct Poly *p2, struct Poly *res)
{
    res->exp = (p1->exp > p2->exp) ? p1->exp : p2->exp;
    for (int i = 0; i <= res->exp; i++)
        res->coeff[i] = p1->coeff[i] + p2->coeff[i];
}

void display(struct Poly *p)
{
    for (int i = p->exp; i >= 0; i--)
    {
        if (p->coeff[i])
        {
            if (i != p->exp && p->coeff[i] > 0)
                printf("+");
            if (i == 0)
                printf("%d", p->coeff[i]);
            else if (i == 1)
                printf("%dx", p->coeff[i]);
            else
                printf("%dx^%d", p->coeff[i], i);
        }
    }
    printf("\n");
}

int main()
{
    struct Poly p1 = {0}, p2 = {0}, result = {0};
    printf("First polynomial:\n");
    read(&p1);
    printf("Second polynomial:\n");
    read(&p2);
    add(&p1, &p2, &result);
    printf("First: ");
    display(&p1);
    printf("Second: ");
    display(&p2);
    printf("Sum: ");
    display(&result);
    return 0;
}
