#include <stdio.h>
struct term
{
    int coef;
    int expo;
};
void disp(struct term poly[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (i + 1 == n)
            printf("%dx^%d\n", poly[i].coef, poly[i].expo);

        else
            printf("%dx^%d +", poly[i].coef, poly[i].expo);
    }
}
void sort(struct term poly[], int n)
{
    int i, j, a;
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (poly[i].expo > poly[j].expo)
            {
                a = poly[i].expo;
                poly[i].expo = poly[j].expo;
                poly[j].expo = a;
                a = poly[i].coef;
                poly[i].coef = poly[j].coef;
                poly[j].coef = a;
            }
        }
    }
}

void read(struct term poly[], int n)
{
    int i;
    printf("Enter the coefficient and exponent for each term\n");
    for (i = 0; i < n; i++)
    {
        printf("For term %d:", i + 1);
        scanf("%d", &poly[i].coef);
        scanf("%d", &poly[i].expo);
    }
    sort(poly, n);
}
int main()
{
    int n;
    printf("Enter the number of terms :");
    scanf("%d", &n);

    struct term poly[n];

    read(poly, n);
    printf("Polinomial\n");
    disp(poly, n);

    return 0;
}
