/*3. Write a simple C program to generate a random number 
 between 0 and 9. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   
    srand(time(NULL));

    int random_number;

    // Generate a random number and keep trying until it's between 1 and 9
    while ((random_number = rand() % 10) == 0) {
        // Continue generating if it's 0
    }

    // Print the random number
    printf("Random number: %d\n", random_number);

    return 0;
}

