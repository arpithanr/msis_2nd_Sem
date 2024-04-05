/* Define and populate an array of size n with double or floating point numbers. 
Create four threads using omp where one of them displays the array elements,
 the second one counts the total sum of the numbers, the third one finds 
 the maximum element in the array, and the fourth one squares every element. 
Use critical section or omp lock routines to ensure that the threads 
do not get into race situation.*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 10

double arr[SIZE];

// Function to display array elements
void displayArray() {
    printf("Array elements:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

// Function to find the sum of array elements
void sumArray(double *sum) {
    *sum = 0.0;
    #pragma omp parallel for reduction(+: *sum)
    for (int i = 0; i < SIZE; i++) {
        *sum += arr[i];
    }
}

// Function to find the maximum element in the array
void maxArray(double *max) {
    *max = arr[0];
    #pragma omp parallel for
    for (int i = 1; i < SIZE; i++) {
        #pragma omp critical
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

// Function to square every element in the array
void squareArray() {
    #pragma omp parallel for
    for (int i = 0; i < SIZE; i++) {
        #pragma omp critical
        arr[i] *= arr[i];
    }
}

int main() {
    // Populate array with random double values
    srand(123); // Seed for reproducibility
    for (int i = 0; i < SIZE; i++) {
        arr[i] = (double)rand() / RAND_MAX * 100.0; // Random values between 0 and 100
    }

    // Display array elements
    displayArray();

    // Sum of array elements
    double sum = 0.0;
    sumArray(&sum);
    printf("\nSum of array elements: %.2f\n", sum);

    // Find maximum element in the array
    double max = 0.0;
    maxArray(&max);
    printf("Maximum element in the array: %.2f\n", max);

    // Square every element in the array
    squareArray();

    // Display array elements after squaring
    printf("\nArray elements after squaring:\n");
    displayArray();

    return 0;
}
