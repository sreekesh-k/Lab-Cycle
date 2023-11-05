#include <stdio.h>

void printarr(int arr[], int pos)
{
    int i;
    if (pos == -1)
    {
        printf("Array is empty\n");
    }
    else
    {
        printf("array[%d]: {", pos + 1);
        for (i = 0; i <= pos; i++)
        {
            if (i != pos)
                printf("%d,", arr[i]);
            else
                printf("%d}\n", arr[i]);
        }
    }
}
int insert(int arr[], int pos)
{
    if (pos == 9)
        printf("Array is full\n");
    else
    {
        int e;
        printf("Enter element: ");
        scanf("%d", &e);
        arr[++pos] = e;
    }
    printarr(arr, pos);
    return pos;
}

void search(int arr[], int pos)
{
    int i, e;
    printf("Enter element to search: ");
    scanf("%d", &e);
    for (i = 0; i <= pos; i++)
    {
        if (arr[i] == e)
        {
            printf("%d is in the position %d\n", e, i);
            return;
        }
    }
    printf("%d is not in this array\n", e);
}
void shift(int i, int arr[], int pos)
{

    for (i; i < pos; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[pos] = '\0';
}
int delete(int arr[], int pos)
{
    int i, temp, e;
    printf("Enter element to delete: ");
    scanf("%d", &e);
    for (i = 0; i <= pos; i++)
    {
        if (arr[i] == e)
        {
            if (i == pos)
            {
                printf("%d (at index %d) is deleted from the array\n", e, i);
                arr[i] = '\0';
            }
            else
            {
                printf("%d (at index %d) is deleted from the array\n", e, i);
                shift(i, arr, pos);
            }
            printf("New ");
            pos = pos - 1;
            printarr(arr, pos);
            return pos;
        }
    }
    printf("%d is not in this array\n", e);
    return pos;
}

void sort(int arr[], int pos)
{
    int j, i, temp;
    for (j = 0; j < pos; j++)
    {
        for (i = 0; i < pos; i++)
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
    printarr(arr, pos);
}
int menu()
{
    int ch;
    printf("***********************\n");
    printf("1.Insert\t2.Search\n3.Delete\t4.Sort\n5.Exit\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}
void process()
{
    int arr[10], pos = -1, ch, e;
    for (ch = menu(); ch != 5; ch = menu())
    {
        switch (ch)
        {
        case 1:

            pos = insert(arr, pos);
            break;
        case 2:
            search(arr, pos);
            break;
        case 3:
            pos = delete (arr, pos);
            break;
        case 4:
            sort(arr, pos);
            break;
        default:
            printf("invalid choice\n");
        }
    }
}

int main()
{
    process();
    return 0;
}
