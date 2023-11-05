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
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (poly[j].expo > poly[j + 1].expo)
            {
                struct term temp = poly[j];
                poly[j] = poly[j + 1];
                poly[j + 1] = temp;
            }
        }
    }
}
int add(struct term poly1[], int n1, struct term poly2[], int n2, struct term result[])
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (poly1[i].expo == poly2[j].expo)
        {
            result[k].expo = poly1[i].expo;
            result[k].coef = poly1[i].coef + poly2[j].coef;
            i++, j++, k++;
        }
        else if (poly1[i].expo > poly2[j].expo)
        {
            result[k] = poly1[i];
            i++, k++;
        }
        else if (poly1[i].expo < poly2[j].expo)
        {
            result[k] = poly2[j];
            j++, k++;
        }
    }
    if (i < n1)
    {
        for (i; i < n1; i++, k++)
            result[k] = poly1[i];
    }
    else if (j < n2)
    {
        for (j; j < n2; j++, k++)
            result[k] = poly2[j];
    }
    return k;
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
    struct term poly1[100], poly2[100], result[100];
    int n1, n2, nresult;
    printf("Enter the number of terms in first polinomial:");
    scanf("%d", &n1);
    read(poly1, n1);

    printf("\nEnter the number of terms in second polinomial:");
    scanf("%d", &n2);
    read(poly2, n2);

    printf("\nPolinomial 1: ");
    disp(poly1, n1);
    printf("\nPolinomial 2: ");
    disp(poly2, n2);

    nresult = add(poly1, n1, poly2, n2, result);
    printf("\nThe sum of polinomials: ");
    disp(result, nresult);
}
