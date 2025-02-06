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
    strcpy(newNode->lastName, lastName);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

StudentNode* insertIntoBST(StudentNode* root, const char* lastName) {
    if (root == NULL) {
        return createStudentNode(lastName);
    }
    
    if (strcmp(lastName, root->lastName) < 0) {
        root->left = insertIntoBST(root->left, lastName);
    } else if (strcmp(lastName, root->lastName) > 0) {
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

int main() {
    FILE* file = fopen("students.txt", "r");
    StudentNode* root = NULL;
    char firstName[MAX_NAME], lastName[MAX_NAME];
    int grade;
    
    while (fscanf(file, "%s %s %d", firstName, lastName, &grade) == 3) {
        root = insertIntoBST(root, lastName);
    }
    
    fclose(file);
    
    // Example search
    char searchName[MAX_NAME];
    printf("Enter last name to search: ");
    scanf("%s", searchName);
    
    StudentNode* result = searchBST(root, searchName);
    if (result) {
        printf("Student found: %s\n", result->lastName);
    } else {
        printf("Student not found.\n");
    }
    
    return 0;
}

