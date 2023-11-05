#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char data[100];
    struct node *next;
    struct node *prev;
};
typedef struct node node;
node *head = NULL;
void insert()
{
    char e[100];
    printf("Enter the string to be inserted:");
    scanf("%s", e);
    if (head == NULL)
    {
        head = (node *)malloc(sizeof(node));
        strcpy(head->data, e);
        head->next = head;
        head->prev = head;
    }
    else
    {
        node *t = head;
        while (t->next != head)
        {
            t = t->next;
        }
        t->next = (node *)malloc(sizeof(node));
        strcpy(t->next->data, e);
        t->next->next = head;
        t->next->prev = t;
        head->prev = t->next;
    }
}

void del()
{
    char e[100];
    printf("Enter the string to be deleted:");
    scanf("%s", e);
    if (head == NULL)
    {
        printf("Empty Circular Doubly Linked List.\n");
    }
    else if (strcmp(head->data, e) == 0 && head->next == head)
    {
        printf("Deleted string %s from the list.\n", head->data);
        head = NULL;
    }
    else if (strcmp(head->data, e) == 0)
    {
        printf("Deleted string %s from the list.\n", head->data);
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
    }
    else
    {
        node *t = head->next;
        while (t != head && strcmp(t->data, e) != 0)
        {
            t = t->next;
        }
        if (t == head)
        {
            printf("%s Element not in the list !\n", e);
        }
        else
        {
            printf("Deleted string %s from the list.\n", t->data);
            t->prev->next = t->next;
            t->next->prev = t->prev;
        }
    }
}
void disp()
{
    if (head == NULL)
    {
        printf("Empty Circular Doubly linked list.\n");
    }
    else
    {
        printf("\n");
        node *t = head;
        do
        {
            printf("%s\t", t->data);
            t = t->next;
        } while (t != head);
    }
    printf("\n");
}
int main()
{
    int ch = 1;

    while (ch)
    {

        printf("\n1.Insert\t2.Delete\n3.Display\t4.Exit\n");
        printf("*************************************************\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            del();
            break;
        case 3:
            disp();
            break;
        case 4:
            break;
        default:
            printf("Invalid choice! Please enter a valid option.\n");
            break;
        }
    }
    return 0;
}
