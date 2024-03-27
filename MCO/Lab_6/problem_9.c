/* Write a multithreaded program to compute the sum of two n*n square order matrices.
Let the intilization of the matrix be done with in the parallel region, just by only one thread*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 5

int matrix1[MAX_SIZE][MAX_SIZE];
int matrix2[MAX_SIZE][MAX_SIZE];
int result_matrix[MAX_SIZE][MAX_SIZE];
int n;

// Function to initialize the matrices with random values
void initializeMatrices() {
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix1[i][j] = rand() % 10; // Random values between 0 and 9
            matrix2[i][j] = rand() % 10; // Random values between 0 and 9
        }
    }
}

// Function to compute the sum of two matrices
void computeMatrixSum() {
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int main() {
    // Get user input for matrix size
    printf("Enter the size of the square matrices: ");
    scanf("%d", &n);

    // Initialize the matrices
    initializeMatrices();

    // Compute the sum of the matrices
    computeMatrixSum();

    // Print the matrices and the result matrix
    printf("Matrix 1:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    printf("\nSum of the Matrices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", result_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}