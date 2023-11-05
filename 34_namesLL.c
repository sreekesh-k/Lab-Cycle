#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char name[100];
    struct Node *next;
};

struct Node *head = NULL;

void insert(char name[])
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->next = head;
    head = newNode;
}

void delete(char name[])
{
    struct Node *current = head;
    struct Node *previous = NULL;

    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            if (previous == NULL)
            {
                head = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Name not found: %s\n", name);
}

void display()
{
    struct Node *t = head;

    while (t != NULL)
    {
        printf("%s\n", t->name);
        t = t->next;
    }
}

void sort()
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    struct Node *sorted = NULL;
    struct Node *current = head;

    while (current != NULL)
    {
        struct Node *next = current->next;
        if (sorted == NULL || strcmp(current->name, sorted->name) <= 0)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            struct Node *search = sorted;
            while (search->next != NULL && strcmp(current->name, search->next->name) > 0)
            {
                search = search->next;
            }
            current->next = search->next;
            search->next = current;
        }
        current = next;
    }

    head = sorted;
}

void reverse()
{
    struct Node *current = head;
    struct Node *previous = NULL;
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    head = previous;
}

int count()
{
    struct Node *current = head;
    int count = 0;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}

int main()
{
    char name[100];
    int choice;

    while (1)
    {
        printf("\n**************************\n");
        printf("1.Insert\t2.Delete\n3.Display\t4.Sort\n5.Reverse\t6.Count\n7.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%s", name);
            insert(name);
            break;

        case 2:
            scanf("%s", name);
            delete (name);
            break;

        case 3:
            printf("Linked List:\n");
            display();
            break;

        case 4:
            sort();
            printf("List sorted.\n");
            display();
            break;

        case 5:
            reverse();
            printf("List reversed.\n");
            display();
            break;

        case 6:
            printf("Number of elements in the list: %d\n", count());
            break;

        case 7:
            exit(0);
        }
    }

    return 0;
}
