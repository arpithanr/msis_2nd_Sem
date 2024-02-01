/*Implement a C function to find the transpose of a given 
matrix. The program should take a matrix as input, compute 
its transpose, and display the result.*/

#include <stdio.h>

void find_transpose(int mat[][100], int rows, int cols) {
    int transpose[cols][rows];  // Transpose matrix

    // Swap rows and columns to create the transpose
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = mat[i][j];
        }
    }

    // Print the transpose matrix
    printf("Transpose of the matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int mat[rows][cols];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    find_transpose(mat, rows, cols);

    return 0;
}
