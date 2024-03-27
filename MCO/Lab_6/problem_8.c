/* Write a multithreaded program to compute the sum of all the elements in a matrix.
Let each thread should determine the partial sum of a column. Let the number of threads 
working together be equal to the number of columns.*/

#include <stdio.h>
#include <pthread.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define NUM_THREADS MAX_COLS

int matrix[MAX_ROWS][MAX_COLS] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
};

int column_sums[MAX_COLS] = {0};

// Function for each thread to calculate partial sum of a column
void *calculateColumnSum(void *arg) {
    int col = *((int *)arg);
    for (int i = 0; i < MAX_ROWS; i++) {
        column_sums[col] += matrix[i][col];
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Create threads to calculate column sums
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, calculateColumnSum, (void *)&thread_ids[i]);
    }

    // Join threads with the main thread
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Calculate total sum of all elements in the matrix
    int total_sum = 0;
    for (int i = 0; i < MAX_COLS; i++) {
        total_sum += column_sums[i];
    }

    // Print the column sums and total sum
    printf("Column Sums:\n");
    for (int i = 0; i < MAX_COLS; i++) {
        printf("Column %d sum: %d\n", i, column_sums[i]);
    }
    printf("Total Sum of Matrix: %d\n", total_sum);

    return 0;
}