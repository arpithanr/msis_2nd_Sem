/*Write a multithreaded program that will find the repetition of a number within a n*n order square matrix. 
(Let the intilization of the matrix be done within the parallel region by just one thread.
 Let the number to be searched be input by the user before entering the parallel region).*/


 #include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define MAX_SIZE 10

int matrix[MAX_SIZE][MAX_SIZE];
int n, search_number, repetitions = 0;

// Function to initialize the matrix with random values
void initializeMatrix() {
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 10; // Random values between 0 and 9
        }
    }
}

// Function to search for repetitions of a number in the matrix
void searchRepetitions() {
    #pragma omp parallel for reduction(+:repetitions)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == search_number) {
                repetitions++;
            }
        }
    }
}

int main() {
    // Get user input for matrix size and number to search
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);
    printf("Enter the number to search for repetitions: ");
    scanf("%d", &search_number);

    // Initialize the matrix
    initializeMatrix();

    // Search for repetitions of the number in the matrix
    searchRepetitions();

    // Print the matrix
    printf("Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Print the number of repetitions found
    printf("Number of repetitions of %d in the matrix: %d\n", search_number, repetitions);

    return 0;
}