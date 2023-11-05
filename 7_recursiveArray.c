#include <stdio.h>
void disp(int arr[], int n)
{
    if (n < 0)
        return;
    disp(arr, n - 1);
    printf("%d ", arr[n]);
}
int main()
{
    int arr[10], n, i;
    printf("Enter Number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter Element %d:", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Array: ");
    disp(arr, n - 1);
    return 0;
}
