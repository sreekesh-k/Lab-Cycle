#include <stdio.h>
#include <stdlib.h>
struct Books
{
    char aName[30], bName[30];
};

int main()
{
    int i, n;
    struct Books *bpoint;
    printf("Enter number of books: ");
    scanf("%d", &n);
    bpoint = (struct Books *)calloc(n, sizeof(struct Books));

    printf("Enter the folowing Book details: \n");
    for (i = 0; i < n; i++)
    {
        printf("For book %d\n", i + 1);
        printf("Enter Book name: ");
        scanf("%s", (bpoint + i)->bName);
        printf("Enter Author name: ");
        scanf("%s", (bpoint + i)->aName);
    }
    printf("Book details stored: \n");
    for (i = 0; i < n; i++)
    {
        if (i > 0 && i % 2 == 0)
        {
            printf("\n");
        }
        printf("%d: ", i + 1);
        printf("%s", ((bpoint + i)->bName));
        printf(" By ");
        printf("%s \t\t", ((bpoint + i)->aName));
    }
    free(bpoint);
    return 0;
}
