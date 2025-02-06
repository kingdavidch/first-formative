#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    int grade;
} Student;

// Swap function for QuickSort
void swap(Student *a, Student *b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for QuickSort
int partition(Student arr[], int low, int high) {
    Student pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].grade <= pivot.grade) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// QuickSort implementation
void quickSort(Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    FILE *inputFile, *outputFile;
    Student students[MAX_STUDENTS];
    int studentCount = 0;

    // Open input file
    inputFile = fopen("students.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    // Read student data
    while (fscanf(inputFile, "%s %s %d", 
           students[studentCount].firstName, 
           students[studentCount].lastName, 
           &students[studentCount].grade) == 3) {
        studentCount++;
    }
    fclose(inputFile);

    // Sort students by grade
    quickSort(students, 0, studentCount - 1);

    // Write sorted data
    outputFile = fopen("sorted_students.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    for (int i = 0; i < studentCount; i++) {
        fprintf(outputFile, "%s %s %d\n", 
                students[i].firstName, 
                students[i].lastName, 
                students[i].grade);
    }
    fclose(outputFile);

    return 0;
}

