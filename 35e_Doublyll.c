#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

typedef struct node node;

node *head = NULL;

void insert(int e)
{

    if (head == NULL)
    {
        head = (node *)malloc(sizeof(node));
        head->data = e;
        head->prev = NULL;
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
        t->next->prev = t;
        t->next->next = NULL;
    }
}

void delete(int e)
{
    if (head == NULL)
    {
        printf("List is empty :(\n");
    }
    else if (head->data == e && head->next == NULL)
    {
        printf("%d is removed from the list\n", e);
        head = NULL;
    }
    else if (head->data == e && head->next != NULL)
    {
        printf("%d is removed from the list\n", e);
        head = head->next;
        head->prev = NULL;
    }
    else
    {
        node *t = head;
        while (t->data != e && t->next != NULL)
        {
            t = t->next;
        }
        if (t->data == e)
        {
            printf("%d is removed from the list\n", e);
            t->prev->next = t->next;
            if (t->next != NULL)
                t->next->prev = t->prev;
        }
        else
        {
            printf("Element not found\n");
        }
    }
}

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

void menu()
{
    char ch;
    int e, sp;
    while (ch != 'f')
    {
        scanf(" %c", &ch);
        switch (ch)
        {
        case 'i':
            scanf("%d", &e);
            insert(e);
            break;
        case 'd':
            scanf("%d", &e);
            delete (e);
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
    printf("1.Insert: i and element to insert\n");
    printf("2.Delete: d and element to delete\n");
    printf("3.Display: z\n");
    printf("4.Finish: f\n");
    printf("*****************************************************\n\n");
    menu();
    /*
    i b 1
    i b 2
    i b 3
    i b 4
    i b 5
    z
    */
    return 0;
}
