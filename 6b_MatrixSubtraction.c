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
void sub(int r, int c, int arr1[r][c], int arr2[r][c])
{
    print(r, c, arr1);
    printf(" - \n");
    print(r, c, arr2);
    int sum[r][c];
    int i, j;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            sum[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
    printf(" = \n");
    print(r, c, sum);
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
    sub(r, c, arr1, arr2);
    return 0;
}
