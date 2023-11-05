#include <stdio.h>
void print(int r, int c, int arr[r][c])
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        printf("|");
        for (j = 0; j < c; j++)
        {
            if (j < c - 1)
                printf(" %d\t", arr[i][j]);
            else
                printf("%d |", arr[i][j]);
        }
        printf("\n");
    }
}

void read(int r, int c, int arr[r][c])
{
    int i, j;
    printf("               [Row,column]\n");
    for (i = 0; i < r; i++)
    {
        printf("Row %d: \n", i + 1);
        for (j = 0; j < c; j++)
        {
            printf("Enter element at [%d,%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("\n");
}
void multi(int r, int c, int arr1[r][c], int arr2[r][c])
{
    print(r, c, arr1);
    printf(" * \n");
    print(r, c, arr2);
    int mult[r][c];
    int i, j, k;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            mult[i][j] = 0;
            for (k = 0; k < c; k++)
            {
                mult[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    printf(" = \n");
    print(r, c, mult);
}

int main()
{
    int i = 0, r, c;
    printf("Enter number of rows: ");
    scanf("%d", &r);
    printf("Enter number of columns: ");
    scanf("%d", &c);

    int arr1[r][c];
    int arr2[r][c];
    printf("For array 1\n");
    read(r, c, arr1);
    printf("For array 2\n");
    read(r, c, arr2);
    multi(r, c, arr1, arr2);
    return 0;
}
