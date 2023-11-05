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
void insert(int e)
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
void del_from_beg()
{
    if (head == NULL)
    {
        printf("Empty linked list.\n");
    }
    else if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        head = head->next;
    }
    disp();
}
void del_from_end()
{
    node *t = head;
    if (head == NULL)
    {
        printf("Empty linked list.\n");
    }
    else if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {

        while (t->next->next != NULL)
        {
            t = t->next;
        }
        t->next = NULL;
    }
    disp();
}
void delete(int e)
{
    if (head == NULL)
        printf("List is empty :(\n");

    else if (head->data == e && head->next == NULL)
        head = NULL;

    else if (head->data == e && head->next != NULL)
        head = head->next;

    else
    {
        node *t = head;
        while (t->next->data != e && t->next->next != NULL)
        {
            t = t->next;
        }
        if (t->next->data == e)
        {
            t->next = t->next->next;
        }
        else
        {
            printf("Element not found\n");
        }
    }
    disp();
}
void menu()
{
    char ch;
    int e;
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
            scanf(" %c", &ch);
            if (ch == 'e')
                del_from_end();

            else if (ch == 'b')
                del_from_beg();

            else
            {
                scanf("%d", &e);
                delete (e);
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
    printf("1.Insert: i and element to insert\n");
    printf("2.Delete : d ,(e or b) or l and element to delete\n");
    printf("3.Display: z\n");
    printf("4.Finish: f\n");
    printf("eg: i 10 will insert 10\n");
    printf("eg: d l 10 will delete 10\n");
    printf("eg: d e will delete 1 element from the end\n");
    printf("*****************************************************\n\n");
    menu();
    return 0;
}
