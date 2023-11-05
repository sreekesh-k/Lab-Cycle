#include <stdio.h>

int main()
{
    int r, c;

    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);

    int matrix[r][c];
    int transpose[c][r];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            scanf("%d", &matrix[i][j]);
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            transpose[j][i] = matrix[i][j];
    }

    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%d\t", matrix[i][j]);

        printf("\n");
    }

    printf("\nTranspose Matrix:\n");
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}
