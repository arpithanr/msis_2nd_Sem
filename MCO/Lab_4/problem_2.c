/* 2. Implement a program to calculate the square of each element in an array in parallel using OpenMP. Use shared variables
for the input array and private variables for the parallel for loop indices*/

#include <stdio.h>
#include <omp.h>

#define SIZE 1000000 // Size of the array

int main() {
    int array[SIZE];
    
    // Initialize the array
    for (int i = 0; i < SIZE; i++) {
        array[i] = i + 1;
    }

    // Parallel computation of squares
    #pragma omp parallel for
    for (int i = 0; i < SIZE; i++) {
        array[i] = array[i] * array[i];
    }

    // Printing the squared array
    printf("Squared array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
