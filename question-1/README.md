## Program Description
This program implements a QuickSort algorithm to sort student records based on their grades in ascending order. The program reads from a text file containing student information and creates a new file with the sorted records.

## Input File Format (students.txt)
Create a text file named `students.txt` with the following format:
```
FirstName LastName Grade
John Smith 85
Emma Johnson 92
Michael Brown 78
```

## How to Run
1. Save the code as `student_quicksort.c`
2. Create `students.txt` with student records
3. Compile: `gcc student_quicksort.c -o student_quicksort`
4. Run: `./student_quicksort`
5. Check `sorted_students.txt` for results

## Features
- Reads student records from text file
- Sorts records by grade in ascending order
- Handles up to 100 students
- Creates sorted output file

## Time Complexity Analysis
- Average Case: O(n log n)
- Worst Case: O(n²)
- Space Complexity: O(log n)

## Why QuickSort over Insertion Sort?
1. Better average-case performance O(n log n) vs O(n²)
2. More efficient for large datasets
3. In-place sorting algorithm
4. Better cache utilization

## Sample Input Data (students.txt)
```
John Smith 85
Emma Johnson 92
Michael Brown 78
Sarah Davis 95
James Wilson 88
```

## Program Limitations
- Maximum 100 students
- Maximum name length: 50 characters
- Grades must be integers between 0 and 100
