#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50

typedef struct StudentNode {
    char lastName[MAX_NAME];
    struct StudentNode* left;
    struct StudentNode* right;
} StudentNode;

StudentNode* createStudentNode(const char* lastName) {
    StudentNode* newNode = malloc(sizeof(StudentNode));
    if (newNode == NULL) return NULL;
    strcpy(newNode->lastName, lastName);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

StudentNode* insertIntoBST(StudentNode* root, const char* lastName) {
    if (root == NULL) {
        return createStudentNode(lastName);
    }
    
    int comparison = strcmp(lastName, root->lastName);
    if (comparison < 0) {
        root->left = insertIntoBST(root->left, lastName);
    } else if (comparison > 0) {
        root->right = insertIntoBST(root->right, lastName);
    }
    
    return root;
}

StudentNode* searchBST(StudentNode* root, const char* lastName) {
    if (root == NULL || strcmp(root->lastName, lastName) == 0) {
        return root;
    }
    
    if (strcmp(lastName, root->lastName) < 0) {
        return searchBST(root->left, lastName);
    }
    
    return searchBST(root->right, lastName);
}

void inorderTraversal(StudentNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%s\n", root->lastName);
        inorderTraversal(root->right);
    }
}

int main() {
    FILE* file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    StudentNode* root = NULL;
    char firstName[MAX_NAME], lastName[MAX_NAME];
    int grade;
    
    while (fscanf(file, "%s %s %d", firstName, lastName, &grade) == 3) {
        root = insertIntoBST(root, lastName);
    }
    
    fclose(file);
    
    printf("Students sorted by last name:\n");
    inorderTraversal(root);
    
    char searchName[MAX_NAME];
    printf("\nEnter last name to search: ");
    scanf("%s", searchName);
    
    StudentNode* result = searchBST(root, searchName);
    if (result) {
        printf("Student found: %s\n", result->lastName);
    } else {
        printf("Student not found.\n");
    }
    
    return 0;
}
