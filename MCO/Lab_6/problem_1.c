/* Write a multithreaded program to multiply every element in an array by a constant number.
Create “4” threads and print the thread number too with the results */

#include <stdio.h>
#include <pthread.h>

#define ARRAY_SIZE 10
#define NUM_THREADS 4

int array[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int constant = 3;

// Function to multiply array elements by a constant
void *multiplyArrayElements(void *thread_id) {
    int tid = *((int *)thread_id);
    for (int i = tid; i < ARRAY_SIZE; i += NUM_THREADS) {
        array[i] *= constant;
        printf("Thread %d processed element %d with result: %d\n", tid, i, array[i]);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Create threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, multiplyArrayElements, (void *)&thread_ids[i]);
    }

    // Join threads with the main thread
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Print the final array
    printf("Final array after multiplication:\n");
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}