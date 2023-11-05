#include <stdio.h>
#include <stdlib.h>
#define K -55;
int n;
void mode(int *freq, int *p)
{
    int temp, i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (*(freq + j) >= *(freq + j + 1))
            {
                temp = *(freq + j);
                *(freq + j) = *(freq + j + 1);
                *(freq + j + 1) = temp;

                temp = *(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = temp;
            }
        }
    }
    printf("Mode = %d (repeated %d times)", *(p + (n - 1)), *(freq + (n - 1)));
}
int main()
{
    printf("Enter number of elements: ");
    int i, j, *p, *freq;
    scanf("%d", &n);
    p = (int *)calloc(n, sizeof(int));
    freq = (int *)calloc(n, sizeof(int));
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        *(freq + i) = 1;
        scanf("%d", p + i);
        if (i > 0)
        {
            for (j = i - 1; j >= 0; j--)
            {
                if (*(p + i) == *(p + j))
                {
                    *(freq + j) += 1;
                    *(freq + i) = 0;
                    *(p + i) = K;
                }
            }
        }
    }
    mode(freq, p);
    free(p);
    free(freq);
    return 0;
}
