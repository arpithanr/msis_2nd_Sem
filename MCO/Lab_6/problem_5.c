/* Write a multithreaded program that will take two numbers as input from the user, num1 and num2.
 The program should list out all the numbers between 0 and num2 which are divisble by num1.
(parallelise the for loop)*/

#include <stdio.h>
#include <pthread.h>

int num1, num2;

// Function to check and print numbers divisible by num1
void *checkDivisibility(void *arg) {
    int divisor = *((int *)arg);
    for (int i = 0; i <= num2; i++) {
        if (i % divisor == 0) {
            printf("%d is divisible by %d\n", i, divisor);
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    
    // Get user input for num1 and num2
    printf("Enter num1: ");
    scanf("%d", &num1);
    printf("Enter num2: ");
    scanf("%d", &num2);

    // Create thread to check divisibility
    pthread_create(&thread, NULL, checkDivisibility, (void *)&num1);

    // Join thread with the main thread
    pthread_join(thread, NULL);

    return 0;
}