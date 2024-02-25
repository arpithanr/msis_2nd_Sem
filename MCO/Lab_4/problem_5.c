/*5. Implement a program to generate the Fibonacci series in parallel using OpenMP. Use shared variables for the result
array and private variables for each thread's local variables.*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 20

int main() {
    int fib[N];
    fib[0] = 0;
    fib[1] = 1;

    // Generate Fibonacci series in parallel
    #pragma omp parallel
    {
        int a = 0, b = 1;
        #pragma omp for
        for (int i = 2; i < N; i++) {
            fib[i] = a + b;
            a = b;
            b = fib[i];
        }
    }

    // Print the Fibonacci series
    printf("Fibonacci Series: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    return 0;
}