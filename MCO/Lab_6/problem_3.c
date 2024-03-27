/* Create two functions, one to add two arrays and one to multiply two arrays.
Write a program that will call these two functions in two separate threads. Also display their thread ids.*/

#include <stdio.h>
#include <pthread.h>

#define ARRAY_SIZE 5

int array1[ARRAY_SIZE] = {1, 2, 3, 4, 5};
int array2[ARRAY_SIZE] = {6, 7, 8, 9, 10};
int result_add[ARRAY_SIZE];
int result_multiply[ARRAY_SIZE];

// Function to add two arrays
void *addArrays(void *thread_id) {
    int tid = *((int *)thread_id);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        result_add[i] = array1[i] + array2[i];
    }
    printf("Thread ID %d: Arrays added successfully.\n", tid);
    pthread_exit(NULL);
}

// Function to multiply two arrays
void *multiplyArrays(void *thread_id) {
    int tid = *((int *)thread_id);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        result_multiply[i] = array1[i] * array2[i];
    }
    printf("Thread ID %d: Arrays multiplied successfully.\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread_add, thread_multiply;
    int thread_id_add = 1;
    int thread_id_multiply = 2;

    // Create threads for adding and multiplying arrays
    pthread_create(&thread_add, NULL, addArrays, (void *)&thread_id_add);
    pthread_create(&thread_multiply, NULL, multiplyArrays, (void *)&thread_id_multiply);

    // Join threads with the main thread
    pthread_join(thread_add, NULL);
    pthread_join(thread_multiply, NULL);

    // Display the results
    printf("Result after addition:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", result_add[i]);
    }
    printf("\n");

    printf("Result after multiplication:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", result_multiply[i]);
    }
    printf("\n");

    return 0;
}