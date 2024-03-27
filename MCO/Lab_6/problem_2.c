/* Write a multithreaded program to add two arrays.
Create “4” threads and print the thread number with each computation that is done. */

#include <stdio.h>
#include <pthread.h>

#define ARRAY_SIZE 5
#define NUM_THREADS 4

int array1[ARRAY_SIZE] = {1, 2, 3, 4, 5};
int array2[ARRAY_SIZE] = {6, 7, 8, 9, 10};
int result[ARRAY_SIZE];

// Function to add two arrays
void *addArrays(void *thread_id) {
    int tid = *((int *)thread_id);
    for (int i = tid; i < ARRAY_SIZE; i += NUM_THREADS) {
        result[i] = array1[i] + array2[i];
        printf("Thread %d computed: %d + %d = %d\n", tid, array1[i], array2[i], result[i]);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Create threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, addArrays, (void *)&thread_ids[i]);
    }

    // Join threads with the main thread
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Print the final result array
    printf("Final result array after addition:\n");
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}