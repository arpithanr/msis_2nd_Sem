/*3. Create a parallel program to calculate the factorial of a number using OpenMP. Use a shared variable for the result,
and private variables for loop indices.*/

#include <stdio.h>
#include <omp.h>

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    
    #pragma omp parallel for reduction(*:result)
    for (int i = 2; i <= n; i++) {
        result *= i;
    }

    return result;
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        unsigned long long result = factorial(number);
        printf("Factorial of %d is: %llu\n", number, result);
    }

    return 0;
}
