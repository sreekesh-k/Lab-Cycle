#include <stdio.h>
void disparr(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void heaptree(int a[], int i)
{
    int t;
    while (i != 0)
    {
        if (a[i] <= a[(i - 1) / 2])
        {
            break;
        }
        else
        {
            t = a[i];
            a[i] = a[(i - 1) / 2];
            a[(i - 1) / 2] = t;
        }
        i = (i - 1) / 2;
    }
}

void heapsort(int a[], int n)
{
    int i, j, lc, rc, t;
    j = n - 1;
    while (j > 0)
    {
        t = a[0];
        a[0] = a[j];
        a[j] = t;
        j--;

        i = 0;
        while (i < j)
        {
            lc = (2 * i) + 1;
            rc = (2 * i) + 2;

            if (lc <= j && rc <= j)
            {
                if (a[i] >= a[lc] && a[i] >= a[rc])
                {
                    break;
                }
                else if (a[lc] >= a[rc])
                {
                    t = a[i];
                    a[i] = a[lc];
                    a[lc] = t;
                    i = lc;
                }
                else
                {
                    t = a[i];
                    a[i] = a[rc];
                    a[rc] = t;
                    i = rc;
                }
            }
            else if (lc <= j && a[lc] > a[i])
            {
                t = a[i];
                a[i] = a[lc];
                a[lc] = t;
                i = lc;
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{
    int n, i;
    printf("Enter the number of elements in the array : ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the Elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        heaptree(a, i);
    }

    printf("Max heap array : ");
    disparr(a, n);

    heapsort(a, n);
    printf("Sorted array   : ");
    disparr(a, n);

    return 0;
}
