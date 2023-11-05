#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

node *head = NULL;

void disp()
{
    if (head == NULL)
    {
        printf("List is empty :(\n");
    }
    else
    {
        node *t = head;
        printf("[Head]");
        while (t != NULL)
        {
            if (t->next != NULL)
            {
                printf("%d ->", t->data);
            }
            else
            {
                printf("%d[Tail]\n", t->data);
            }
            t = t->next;
        }
    }
}
void insertend(int e)
{

    if (head == NULL)
    {
        head = (node *)malloc(sizeof(node));
        head->data = e;
        head->next = NULL;
    }
    else
    {
        node *t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = (node *)malloc(sizeof(node));
        t->next->data = e;
        t->next->next = NULL;
    }
    disp();
}
void insertfirst(int e)
{

    if (head == NULL)
    {
        head = (node *)malloc(sizeof(node));
        head->data = e;
        head->next = NULL;
    }
    else
    {
        node *t = head;
        head = (node *)malloc(sizeof(node));
        head->data = e;
        head->next = t;
    }
    disp();
}
void insertsp(int f)
{
    int e;
    node *t = head;
    node *a;
    while (t != NULL)
    {
        if (t->data == f)
        {
            printf("Enter the element to be inserted after %d:", f);
            scanf("%d", &e);
            a = t->next;
            t->next = (node *)malloc(sizeof(node));
            t->next->data = e;
            t->next->next = a;
            disp();
            return;
        }
        else
        {
            t = t->next;
        }
    }
    printf("The element %d is not in the list!\n", f);
}

void menu()
{
    char ch;
    int e, f;
    while (ch != 'f')
    {
        scanf(" %c", &ch);
        switch (ch)
        {
        case 'i':
            scanf(" %c", &ch);
            if (ch == 'b')
            {
                scanf("%d", &e);
                insertfirst(e);
            }
            else if (ch == 'e')
            {
                scanf("%d", &e);
                insertend(e);
            }
            else
            {
                scanf("%d", &f);
                insertsp(f);
            }
            break;
        case 'z':
            disp();
            break;
        case 'f':
            printf(".........exit\n");
            break;
        default:
            printf("Opps.. something went wrong,Read instructions :(\n");
            break;
        }
    }
}

int main()
{
    printf("Instructions:\n");
    printf("1.Insert: i,(b or e) and element to insert\n");
    printf("2.Insert After specific element : i, l ,specefic element\n");
    printf("3.Display: z\n");
    printf("4.Finish: f\n");
    printf("eg: i b 10 will insert 10 in the begining of the list\n");
    printf("eg: i l 10 will check if 10 is present ,if yes then it will ask element to insert after 10\n");
    printf("*****************************************************\n\n");
    menu();
    return 0;
}
