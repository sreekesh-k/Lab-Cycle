#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct node
{
    char data[100];
    struct node *left;
    struct node *right;
};
typedef struct node tree;
tree *root = NULL;
void insert(char e[])
{
    tree *p, *x;
    if (root == NULL)
    {
        root = (tree *)malloc(sizeof(tree));
        strcpy(root->data, e);
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        p = root;
        while (p != NULL)
        {
            x = p;
            if (strcmp(p->data, e) > 0)
                p = p->left;
            else
                p = p->right;
        }
        if (strcmp(x->data, e) < 0)
        {
            x->right = (tree *)malloc(sizeof(tree));
            strcpy(x->right->data, e);
            x->right->left = NULL;
            x->right->right = NULL;
        }
        else
        {
            x->left = (tree *)malloc(sizeof(tree));
            strcpy(x->left->data, e);
            x->left->left = NULL;
            x->left->right = NULL;
        }
    }
}
void inorder(tree *r)
{
    if (r != NULL)
    {
        inorder(r->left);
        printf("%s\n", r->data);
        inorder(r->right);
    }
}
int main()
{
    insert("rahul");
    insert("amal");
    insert("bimal");
    insert("kamal");
    insert("thomas");
    insert("paul");
    insert("khan");
    printf("Inorder: \n");
    inorder(root);
    return 0;
}
