#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* left; 
    struct node* right;
} node;

node* initialise_node(int value) 
{  
    node* new_node = (node*) malloc(sizeof(node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}    

node* insert(int value, node *tnode)
{
    if (tnode == NULL) {
     return initialise_node(value);
    }
    
    if (value <= tnode->value) {
        tnode->left = insert(value, tnode->left);
    }

    else if (value > tnode->value) {
        tnode->right = insert(value, tnode->right);
    }
    
    return tnode;
}

void display(node* tnode)
{
   if(tnode==NULL)
   {
       return;
   }
   display(tnode->left);
   printf("%d ", tnode->value);
   display(tnode->right);
}

int allpath(node *root, int path)
{
    if (root == NULL)
    {
        return 0;
    }
    path += root->value;
    if (root->left == NULL && root->right == NULL)
    {
        return path;
    }
    return allpath(root->left, path) + allpath(root->right, path);
}
int allpathsum(node *tnode)
{
    if (tnode == NULL)
    {
        return 0;
    }
    return allpath(tnode, 0);
}


int main() {
    int i, num, value,sum;
    node *root = NULL;
    scanf("%d", &num);
    for (i = 0; i < num; i++){
        scanf("%d",&value);
        root = insert(value, root);
    }
    display(root);
   sum = allpathsum(root);
    printf("\nsum of all path in BST= %d", sum);
    return 0;
}