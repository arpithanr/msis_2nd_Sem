#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define MAX_ROWS 100
#define MAX_COLS 100
 
int matrix[MAX_ROWS][MAX_COLS];
 
void populateMatrix(int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
}
 
void sequentialRowOperations(int rows, int cols) {
    int positives[MAX_ROWS] = {0};
    int negatives[MAX_ROWS] = {0};
    int zeros[MAX_ROWS] = {0};
 
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] > 0)
                positives[i]++;
            else if (matrix[i][j] < 0)
                negatives[i]++;
            else
                zeros[i]++;
        }
    }
 
    printf("Sequential Row-wise Results:\n");
    for (int i = 0; i < rows; ++i) {
        printf("Row %d: Positive numbers: %d, Negative numbers: %d, Zeros: %d\n", i+1, positives[i], negatives[i], zeros[i]);
    }
}
 
void sequentialColumnOperations(int rows, int cols) {
    int minCol[MAX_COLS];
 
    for (int j = 0; j < cols; ++j) {
        minCol[j] = matrix[0][j];
        for (int i = 1; i < rows; ++i) {
            if (matrix[i][j] < minCol[j]) {
                minCol[j] = matrix[i][j];
            }
        }
    }
 
    printf("\nSequential Column-wise Results:\n");
    for (int j = 0; j < cols; ++j) {
        printf("Column %d: Smallest number: %d\n", j+1, minCol[j]);
    }
}
 
int main() {
    int m, n;
 
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &m, &n);
 
    populateMatrix(m, n);
 
    clock_t start_time = clock();
 
    sequentialRowOperations(m, n);
    sequentialColumnOperations(m, n);
 
    clock_t end_time = clock();
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
 
    printf("\nSequential program execution time: %.6f seconds\n", elapsed_time);
 
    return 0;
}