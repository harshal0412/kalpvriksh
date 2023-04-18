
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* init_node(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->left = NULL;
	node->right = NULL;
	node->data = data;
	return (node);
}

struct node* insert(struct node* bnode, int data)
{
    if (bnode == NULL)
        return init_node(data);

    if (data < bnode->data)
        bnode->left = insert(bnode->left, data);

    else
        bnode->right = insert(bnode->right, data);

    return bnode;
}

void preorder_traversal(struct node* bnode)
{
    if (bnode == NULL)
        return;
    printf("%d ", bnode->data);
    preorder_traversal(bnode->left);
    preorder_traversal(bnode->right);
}

void inorder_traversal(struct node* bnode)
{
	if (bnode == NULL)
		return;

	inorder_traversal(bnode->left);
	printf("%d ", bnode->data);

	inorder_traversal(bnode->right);
}

void postorder_traversal(struct node* bnode)
{
    if (bnode == NULL)
        return;
    postorder_traversal(bnode->left);
    postorder_traversal(bnode->right);
    printf("%d ", bnode->data);
}

struct node* minnode(struct node* bnode)
{
    struct node* curr = bnode;
    while (curr && curr->left != NULL)
        curr = curr->left;
    return curr;
}
 

struct node* deleteNode(struct node* root, int data)
{
    if (root == NULL)
       {
       	 return root;
	   }
 
    if (data < root->data)
        {
		root->left = deleteNode(root->left, data);
		}
 
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
 
    else {
        
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 
        struct node* temp = minnode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
	struct node* node_to_be_deleted = NULL;
	struct node* root = NULL;
	root = insert(root, 70);
    root = insert(root, 30);
    root = insert(root, 90);
    root = insert(root, 20);
    root = insert(root, 50);
    root = insert(root, 80);
    root = insert(root, 100);

	printf("\nPreorder traversal of is \n");
	preorder_traversal(root);

	printf("\nInorder traversal is \n");
	inorder_traversal(root);

	printf("\nPostorder traversal of is \n");
	postorder_traversal(root);
	root = deleteNode(root,20);

	printf("\nAfter node deletion tree is \n");
	inorder_traversal(root);
	return 0;
}

