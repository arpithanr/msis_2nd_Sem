/* Write a mulithreaded program to multiply every element in a matrix with a constant number.
The numbers in even rows should be multiplied by even numbered threads, and the number in odd 
rows should be multiplied by odd numbered threads. Print the thread number after each multiplication.*/

#include <stdio.h>
#include <pthread.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define NUM_THREADS 2

int matrix[MAX_ROWS][MAX_COLS] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
};

int constant = 3;

// Function for even and odd numbered threads to multiply rows
void *multiplyRows(void *arg) {
    int tid = *((int *)arg);
    for (int i = tid; i < MAX_ROWS; i += NUM_THREADS) {
        for (int j = 0; j < MAX_COLS; j++) {
            matrix[i][j] *= constant;
            printf("Thread %d multiplied element at row %d, column %d with result: %d\n", tid, i, j, matrix[i][j]);
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Create threads for even and odd row multiplication
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, multiplyRows, (void *)&thread_ids[i]);
    }

    // Join threads with the main thread
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the updated matrix
    printf("Updated Matrix:\n");
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}