#include <stdio.h>

void disp(int arr[], int n)
{
    int i;
    printf("array[%d]: {", n);
    for (i = 0; i < n; i++)
    {
        if (i < n - 1)
            printf("%d,", arr[i]);
        else
            printf("%d}\n", arr[i]);
    }
}
void sort(int arr[], int n)
{
    int j, i, temp;
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
    printf("Sorted ");
    disp(arr, n);
}
void read(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("your ");
    disp(arr, n);
    sort(arr, n);
}

int main()
{
    int i, n, arr[n];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    read(arr, n);

    return 0;
}
