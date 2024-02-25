/*4. Write a program to find the minimum element in an array in parallel using OpenMP. Use shared variables for the array
and the minimum value, and private variables for loop indices.*/
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define ARRAY_SIZE 1000000

int main() {
    int array[ARRAY_SIZE];
    int min_value = array[0]; // Initialize min_value with the first element of the array

    // Fill the array with random values
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000; // Generate random numbers between 0 and 999
    }

    // Find the minimum element in parallel
    #pragma omp parallel for shared(array, min_value)
    for (int i = 0; i < ARRAY_SIZE; i++) {
        #pragma omp critical
        {
            if (array[i] < min_value) {
                min_value = array[i];
            }
        }
    }

    printf("The minimum element in the array is: %d\n", min_value);

    return 0;
}
