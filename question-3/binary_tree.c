#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) return NULL;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* buildTree(int arr[], int size) {
    if (size == 0) return NULL;
    
    TreeNode** nodes = malloc(size * sizeof(TreeNode*));
    for (int i = 0; i < size; i++) {
        nodes[i] = createNode(arr[i]);
    }

    for (int i = 0; i < size; i++) {
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;
        
        if (leftIndex < size) nodes[i]->left = nodes[leftIndex];
        if (rightIndex < size) nodes[i]->right = nodes[rightIndex];
    }

    TreeNode* root = nodes[0];
    free(nodes);
    return root;
}

void printLeafNodes(TreeNode* node) {
    if (node == NULL) return;
    
    if (node->left == NULL && node->right == NULL) {
        printf("%d ", node->data);
        return;
    }
    
    printLeafNodes(node->left);
    printLeafNodes(node->right);
}

TreeNode* findParent(TreeNode* root, int value) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) 
        return NULL;
        
    if ((root->left && root->left->data == value) || 
        (root->right && root->right->data == value)) {
        return root;
    }
    
    TreeNode* leftResult = findParent(root->left, value);
    if (leftResult) return leftResult;
    
    return findParent(root->right, value);
}

void printSiblings(TreeNode* root, int value) {
    TreeNode* parent = findParent(root, value);
    if (!parent) {
        printf("No siblings found (no parent)\n");
        return;
    }
    
    if (parent->left && parent->left->data != value) 
        printf("%d ", parent->left->data);
    if (parent->right && parent->right->data != value) 
        printf("%d ", parent->right->data);
}

void printGrandchildren(TreeNode* root, int value) {
    TreeNode* current = NULL;
    // Find the node
    if (root->data == value) current = root;
    else {
        // Simple search implementation for demo
        TreeNode* queue[100];
        int front = 0, rear = 0;
        queue[rear++] = root;
        
        while (front < rear) {
            TreeNode* node = queue[front++];
            if (node->data == value) {
                current = node;
                break;
            }
            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
    }
    
    if (!current) {
        printf("Node not found\n");
        return;
    }
    
    printf("Grandchildren: ");
    if (current->left) {
        if (current->left->left) printf("%d ", current->left->left->data);
        if (current->left->right) printf("%d ", current->left->right->data);
    }
    if (current->right) {
        if (current->right->left) printf("%d ", current->right->left->data);
        if (current->right->right) printf("%d ", current->right->right->data);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    TreeNode* root = buildTree(arr, size);
    
    printf("Leaf nodes: ");
    printLeafNodes(root);
    printf("\n");
    
    int nodeValue = 2;  // Example node to find siblings and grandchildren
    printf("Siblings of node %d: ", nodeValue);
    printSiblings(root, nodeValue);
    printf("\n");
    
    printf("Parent of node %d: ", nodeValue);
    TreeNode* parent = findParent(root, nodeValue);
    if (parent) printf("%d", parent->data);
    printf("\n");
    
    printGrandchildren(root, nodeValue);
    
    return 0;
}
