#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* buildTree(int arr[], int n) {
    if (n == 0) return NULL;
    
    TreeNode** nodes = malloc(n * sizeof(TreeNode*));
    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;
        
        if (leftIndex < n) nodes[i]->left = nodes[leftIndex];
        if (rightIndex < n) nodes[i]->right = nodes[rightIndex];
    }

    TreeNode* root = nodes[0];
    free(nodes);
    return root;
}

void printLeafNodes(TreeNode* node) {
    if (node == NULL) return;
    
    if (node->left == NULL && node->right == NULL) {
        printf("%d ", node->data);
    }
    
    printLeafNodes(node->left);
    printLeafNodes(node->right);
}

TreeNode* findParent(TreeNode* root, int value, TreeNode* parent) {
    if (root == NULL) return NULL;
    
    if (root->data == value) return parent;
    
    TreeNode* leftParent = findParent(root->left, value, root);
    if (leftParent) return leftParent;
    
    return findParent(root->right, value, root);
}

void printSiblings(TreeNode* root, int value) {
    TreeNode* parent = findParent(root, value, NULL);
    if (!parent) return;
    
    if (parent->left && parent->left->data != value) 
        printf("Sibling: %d\n", parent->left->data);
    if (parent->right && parent->right->data != value) 
        printf("Sibling: %d\n", parent->right->data);
}

void printGrandchildren(TreeNode* node) {
    if (!node) return;
    
    if (node->left) {
        if (node->left->left) printf("Grandchild: %d\n", node->left->left->data);
        if (node->left->right) printf("Grandchild: %d\n", node->left->right->data);
    }
    
    if (node->right) {
        if (node->right->left) printf("Grandchild: %d\n", node->right->left->data);
        if (node->right->right) printf("Grandchild: %d\n", node->right->right->data);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    TreeNode* root = buildTree(arr, n);
    
    printf("Leaf Nodes: ");
    printLeafNodes(root);
    
    return 0;
}

