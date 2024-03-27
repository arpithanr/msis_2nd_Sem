/* Write a multithreaded program to multiply every element in the array by a constant. 
The even numbered threads should multiply the elements in the even indices of the array 
and the odd numbered threads should multiply the elements present in the odd indices of the array.
 (Assume 0 to be the starting even index).*/

 #include <stdio.h>
#include <pthread.h>

#define ARRAY_SIZE 10
#define NUM_THREADS 4

int array[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int constant = 3;

// Function for even numbered threads to multiply even indices
void *multiplyEvenIndices(void *thread_id) {
    int tid = *((int *)thread_id);
    for (int i = 0; i < ARRAY_SIZE; i += 2) {
        if (i % NUM_THREADS == tid) {
            array[i] *= constant;
            printf("Thread %d processed element at index %d with result: %d\n", tid, i, array[i]);
        }
    }
    pthread_exit(NULL);
}

// Function for odd numbered threads to multiply odd indices
void *multiplyOddIndices(void *thread_id) {
    int tid = *((int *)thread_id);
    for (int i = 1; i < ARRAY_SIZE; i += 2) {
        if (i % NUM_THREADS == tid) {
            array[i] *= constant;
            printf("Thread %d processed element at index %d with result: %d\n", tid, i, array[i]);
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Create threads for even and odd index multiplication
    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_ids[i] = i;
        if (i % 2 == 0) {
            pthread_create(&threads[i], NULL, multiplyEvenIndices, (void *)&thread_ids[i]);
        } else {
            pthread_create(&threads[i], NULL, multiplyOddIndices, (void *)&thread_ids[i]);
        }
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