/* 6. Write a program to transpose a matrix in parallel using OpenMP. Use shared variables for the input and output
matrices and private variables for loop indices*/

#include <stdio.h>
#include <omp.h>

#define ROWS 3
#define COLS 3

int main() {
    int matrix[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int transpose[COLS][ROWS];

    // Transpose the matrix in parallel
    #pragma omp parallel for shared(matrix, transpose)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Print the original matrix
    printf("Original Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Print the transposed matrix
    printf("Transposed Matrix:\n");
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}