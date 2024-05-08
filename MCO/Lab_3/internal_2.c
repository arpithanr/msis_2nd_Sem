/* Write a parallel program to determine the sum of elements of an integer matrix of order 3×4 . 
Create column number of threads where each thread compute the summation  of a distinct column . 
Display the  partial sum by the thread each , and the total sum by the master thread. In openmp C*/

#include <stdio.h>
#include <omp.h>

#define ROWS 3
#define COLS 4

int matrix[ROWS][COLS] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};

int main() {
    int total_sum = 0;

    #pragma omp parallel num_threads(COLS)
    {
        int column_sum = 0;
        int column_index = omp_get_thread_num();

        for (int row = 0; row < ROWS; row++) {
            column_sum += matrix[row][column_index];
        }

        printf("Partial sum of column %d: %d\n", column_index, column_sum);

        #pragma omp critical
        {
            total_sum += column_sum;
        }
    }

    printf("Total sum: %d\n", total_sum);
    return 0;
}