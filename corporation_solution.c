#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    char data[20];
    int level;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(const char* data, int level) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(newNode->data, data);
    newNode->level = level;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* findNode(TreeNode* node, const char* data) {
    if (node == NULL) {
        return NULL;
    }

    if (strcmp(node->data, data) == 0) {
        return node;
    }

    TreeNode* foundNode = findNode(node->left, data);
    if (foundNode == NULL) {
        foundNode = findNode(node->right, data);
    }

    return foundNode;
}

TreeNode* checktown(TreeNode* root, TreeNode* node1, TreeNode* node2) {
    if (root == NULL || node1 == NULL || node2 == NULL) {
        return NULL;
    }

    if (root == node1 || root == node2) {
        return root;
    }

    TreeNode* left = checktown(root->left, node1, node2);
    TreeNode* right = checktown(root->right, node1, node2);

    if (left != NULL && right != NULL) {
        return root;
    }

    return (left != NULL) ? left : right;
}

TreeNode* checksuburb(TreeNode* root, TreeNode* node) {
    if (root == NULL || node == NULL) {
        return NULL;
    }

    if (root->left == node || root->right == node) {
        return root;
    }

    TreeNode* left = checksuburb(root->left, node);
    TreeNode* right = checksuburb(root->right, node);

    if (left != NULL) {
        return left;
    } else if (right != NULL) {
        return right;
    }

    return NULL;
}

TreeNode* checkcity(TreeNode* root, TreeNode* node) {
    if (root == NULL || node == NULL || node->level < 3) {
        return NULL;
    }

    if (node->level == 3) {
        return root;
    }

    TreeNode* left = checkcity(root->left, node);
    TreeNode* right = checkcity(root->right, node);

    if (left != NULL) {
        return left;
    } else if (right != NULL) {
        return right;
    }

    return NULL;
}
int main() {
    TreeNode* root = createNode("Bangalore", 1);
    TreeNode* eastNode = createNode("Bangalore East", 2);
    TreeNode* westNode = createNode("Bangalore West", 2);
    TreeNode* aNode = createNode("A Town", 3);
    TreeNode* bNode = createNode("B Town", 3);
    TreeNode* cNode = createNode("C Town", 3);
    TreeNode* dNode = createNode("D Town", 3);

    root->left = eastNode;
    root->right = westNode;
    eastNode->left = aNode;
    eastNode->right = bNode;
    westNode->left = cNode;
    westNode->right = dNode;
    aNode->left = createNode("56001", 4);
    aNode->right = createNode("56002", 4);
    bNode->left = createNode("56003", 4);
    bNode->right = createNode("56004", 4);
    cNode->left = createNode("56005", 4);
    cNode->right = createNode("56006", 4);
    dNode->left = createNode("56007", 4);
    dNode->right = createNode("56008", 4);

   const char* corp1 = "56001";
   const char* corp2 = "56008";

    TreeNode* node1 = findNode(root, corp1);
    TreeNode* node2 = findNode(root, corp2);

    if (node1 != NULL && node2 != NULL) {
        TreeNode* town = checktown(root, node1, node2);
        TreeNode* suburb = checksuburb(root, town);
		TreeNode* city = checkcity(root, town);
		if (city->data != NULL && suburb->data != NULL )
        	{
        		printf("output: %s, %s, %s\n", town->data,suburb->data,city->data);
			}
     else if(city->data == NULL && suburb->data != NULL ) {
    	printf("output: %s, %s\n", town->data,suburb->data);
        
    }else{
    	printf(town->data);
	}
}
    return 0;
}