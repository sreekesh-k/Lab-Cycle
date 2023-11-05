#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *mallocArray, *callocArray, i;
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);

    mallocArray = (int *)malloc(size * sizeof(int));

    printf("Enter any %d integers for mallocArray:\n", size);
    for (i = 0; i < size; i++)
        scanf("%d", &mallocArray[i]);

    callocArray = (int *)calloc(size, sizeof(int));
    printf("\nEnter any %d integers for callocArray:\n", size);
    for (i = 0; i < size; i++)
        scanf("%d", &callocArray[i]);

    printf("\nmallocArray: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", mallocArray[i]);
    }

    printf("\ncallocArray: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", callocArray[i]);
    }

    free(mallocArray);
    free(callocArray);
    return 0;
}
