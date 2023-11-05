#include <stdio.h>
int arr[10], pos = -1;
void printarr()
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
void insert()
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
    printarr();
}

void search()
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
void shift(int i)
{

    for (i; i <= pos; i++)
    {
        arr[i] = arr[i + 1];
    }
    --pos;
}
void delete()
{
    int i, temp, e;
    printf("Enter element to delete: ");
    scanf("%d", &e);
    for (i = 0; i <= pos; i++)
    {
        if (arr[i] == e)
        {
            printf("%d (at index %d) is deleted from the array\n", e, i);
            shift(i);
            printf("New ");
            printarr();
            return;
        }
    }
    printf("%d is not in this array\n", e);
}

void sort()
{
    int j, i, temp;
    for (j = 0; j <= pos - 1; j++)
    {
        for (i = 0; i <= pos - 1; i++)
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
    printarr();
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
    int ch, e;
    for (ch = menu(); ch != 5; ch = menu())
    {
        switch (ch)
        {
        case 1:

            insert();
            break;
        case 2:
            search();
            break;
        case 3:
            delete ();
            break;
        case 4:
            sort();
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
