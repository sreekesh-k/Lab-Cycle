#include <stdio.h>

int poly[30];

void disp(int n)
{
    int i;
    for (i = 0; i < n;)
    {
        if (i + 2 == n)
            printf("%dx^%d\n", poly[i++], poly[i++]);
        else
            printf("%dx^%d +", poly[i++], poly[i++]);
    }
}

int main()
{
    printf("instructions\nEnter x then its coeff and its exponent\neg:x 1 2 is 1x^2\nEnter 'f' when finish\n");
    printf("**************************\n");
    /*x 1 2
      x 2 3
      x 3 4*/
    char ch = 'x';
    int i = 0;
    printf("Enter Polynomial\n");
    while (ch)
    {
        scanf(" %c", &ch);
        if (ch == 'f')
            break;
        scanf("%d%d", &poly[i++], &poly[i++]);
    }
    printf("\nYour Polynomial\n");
    disp(i);
    return 0;
}
