/*1. Illustrate loop parallelism with the for loop by writing a program to calculate the sum of an array in parallel using
OpenMP. (Use a shared variable for the result and private variables for loop indices). */

#include <stdio.h>
#include <omp.h>

#define ARRAY_SIZE 1000000

int main() {
    int i, sum = 0;
    int array[ARRAY_SIZE];

    // Initialize the array
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i;
    }

    // Calculate the sum in parallel
    #pragma omp parallel for private(i) shared(sum)
    for (i = 0; i < ARRAY_SIZE; i++) {
        #pragma omp atomic
        sum += array[i];
    }

    printf("The sum of the array is %d\n", sum);

    return 0;
}