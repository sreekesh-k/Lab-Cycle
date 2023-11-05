#include <stdio.h>
#include <stdlib.h>
void mean(int *p, int n)
{
    int i;
    double sum = 0;
    for (i = 0; i < n; i++)
        sum += *(p + i);
    printf("Mean = %.2f", sum / n);
}

int main()
{
    printf("Enter number of elements: ");
    int n, i, *p;
    scanf("%d", &n);
    p = (int *)malloc(sizeof(int) * n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", p + i);

    mean(p, n);

    free(p);
    return 0;
}
