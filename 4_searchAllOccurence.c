#include <stdio.h>

void printarr(int arr[], int pos)
{
    int i;
    printf("array[%d]: {", pos + 1);
    for (i = 0; i <= pos; i++)
    {
        if (i != pos)
            printf("%d,", arr[i]);
        else
            printf("%d}\n", arr[i]);
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
    int i, e, flag = 0;
    printf("Enter element to search: ");
    scanf("%d", &e);
    for (i = 0; i <= pos; i++)
    {

        if (arr[i] == e)
        {
            if (flag > 0)
                printf("also found at the position %d\n", i);
            else
                printf("%d is in the position %d\n", e, i);
            flag++;
        }
    }
    if (flag == 0)
        printf("%d is not in this array\n", e);
}
int menu()
{
    int ch;
    printf("***********************\n");
    printf("1.Insert\t2.Search\t3.Exit\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}
int main()
{

    int arr[10], pos = -1, ch, e;
    for (ch = menu(); ch != 3; ch = menu())
    {
        switch (ch)
        {
        case 1:
            pos = insert(arr, pos);
            break;
        case 2:
            search(arr, pos);
            break;
        default:
            printf("invalid choice\n");
        }
    }

    return 0;
}
