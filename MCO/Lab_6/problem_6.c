/* Write a multithreaded program that will compare two arrays, and print all the common elements and their count*/

#include <stdio.h>
#include <pthread.h>

#define ARRAY_SIZE 5

int array1[ARRAY_SIZE] = {1, 2, 3, 4, 5};
int array2[ARRAY_SIZE] = {3, 4, 5, 6, 7};
int common_elements[ARRAY_SIZE];
int common_count = 0;

// Function to compare arrays and find common elements
void *findCommonElements(void *arg) {
    int tid = *((int *)arg);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            if (array1[i] == array2[j]) {
                common_elements[common_count++] = array1[i];
                break; // Break to avoid duplicates
            }
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    int thread_id = 1;

    // Create thread to find common elements
    pthread_create(&thread, NULL, findCommonElements, (void *)&thread_id);

    // Join thread with the main thread
    pthread_join(thread, NULL);

    // Print common elements and their count
    printf("Common elements and their count:\n");
    for (int i = 0; i < common_count; i++) {
        printf("%d ", common_elements[i]);
    }
    printf("\nTotal common elements: %d\n", common_count);

    return 0;
}