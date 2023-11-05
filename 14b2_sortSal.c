#include <stdio.h>
#include <string.h>
int pos = -1;
struct employees
{
    int eno;
    char ename[30];
    int esal;
    int dno;
};
void disp(struct employees emp[])
{
    int i;
    for (i = 0; i <= pos; i++)
    {
        printf("EMPLOYEE %d", i + 1);
        printf("\nEmp no: %d", emp[i].eno);
        printf("\nEmp name: %s", emp[i].ename);
        printf("\nEmp salary: %d", emp[i].esal);
        printf("\nEmp dept.no: %d\n", emp[i].dno);
        printf("*********************************\n");
    }
}
void sort_sal(struct employees emp[])
{
    int i, j;
    struct employees temp;
    for (i = 0; i <= pos - 1; i++)
    {
        for (j = 0; j <= pos - 1; j++)
        {
            if (emp[j].esal > emp[j + 1].esal)
            {
                temp = emp[j];
                emp[j] = emp[j + 1];
                emp[j + 1] = temp;
            }
        }
    }
    printf("Sorted.");
    disp(emp);
}

void insert(struct employees emp[], int n)
{
    if (pos == n - 1)
    {
        printf("Employee list is full\n");
    }
    else
    {
        static int i = 0;
        printf("\nFor employee %d -\n", ++i);
        printf("Enter the employee number: ");
        scanf("%d", &emp[++pos].eno);
        printf("Enter the employee name:");
        scanf("%s", emp[pos].ename);
        printf("Enter the employee salary:");
        scanf("%d", &emp[pos].esal);
        printf("Enter the department no:");
        scanf("%d", &emp[pos].dno);
    }
}
int menu()
{
    int e;

    printf("\n1.Insert\t\t2.Sort by Salary\n3.View emp details\t4.Exit");
    printf("\n*********************************");
    printf("\nEnter your choice:");
    scanf("%d", &e);
    return e;
}

void process(struct employees emp[], int n)
{
    int ch;
    for (ch = menu(); ch != 4; ch = menu())
    {
        switch (ch)
        {
        case 1:
            insert(emp, n);
            break;
        case 2:
            sort_sal(emp);
            break;
        case 3:
            disp(emp);
            break;
        default:
            printf("Enter a valid choice.");
            break;
        }
    }
}
int main()
{
    int n;
    printf("\nEnter the number of employees : ");
    scanf("%d", &n);
    struct employees emp[n];
    process(emp, n);
    return 0;
}
