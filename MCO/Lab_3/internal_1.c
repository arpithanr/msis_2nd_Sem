#include <stdio.h>
#include <omp.h>
 
#define ARRAY_SIZE 20
 
int main() {
int array[ARRAY_SIZE];
int sum = 0;
 
// Initialize array
for (int i = 0; i < ARRAY_SIZE; i++) {
array[i] = i + 1; // Filling the array with numbers 1 to ARRAY_SIZE
}
omp_set_num_threads(4);
// Calculate sum in parallel
#pragma omp parallel for reduction(+:sum)
for (int i = 0; i < ARRAY_SIZE; i++) {
sum += array[i];
}
 
printf("Sum of array elements: %d\n", sum);
 
return 0;
}