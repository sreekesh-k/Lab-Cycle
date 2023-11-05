#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
node *head = NULL;
void insert()
{
    int e;
    printf("Enter the element to be inserted:");
    scanf("%d", &e);
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
}
void reverse()
{
    if (head == NULL)
    {
        printf("Empty linked list !");
    }
    else if (head->next == NULL)
    {
        printf("Only one element in the list... Enter more elements.\n");
    }
    else
    {
        node *n = NULL;
        node *t = head;
        node *p = NULL;
        while (t != NULL)
        {
            n = t->next;
            t->next = p;
            p = t;
            t = n;
        }
        head = p;
        printf("Reversed elements :");
        while (p != NULL)
        {
            printf("%d\t", p->data);
            p = p->next;
        }
    }
    printf("\n");
}
int main()
{
    int ch;

    do
    {

        printf("1.Insert\n2.Reverse\n3.Exit\n");
        printf("*************************\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            reverse();
            break;
        case 3:
            break;
        default:
            printf("Enter a valid choice !");
            break;
        }
    } while (ch != 3);
    return 0;
}
