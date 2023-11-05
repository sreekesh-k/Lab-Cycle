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

int multiply(struct term poly1[], int n1, struct term poly2[], int n2, struct term result[])
{
    int k = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            result[k].expo = poly1[i].expo + poly2[j].expo;
            result[k].coef = poly1[i].coef * poly2[j].coef;
            k++;
        }
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
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    read(poly1, n1);

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);
    read(poly2, n2);

    printf("\nPolynomial 1: ");
    disp(poly1, n1);
    printf("Polynomial 2: ");
    disp(poly2, n2);

    nresult = multiply(poly1, n1, poly2, n2, result);
    printf("\nThe product of polynomials: ");
    disp(result, nresult);
}
