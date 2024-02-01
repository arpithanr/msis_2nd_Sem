/*3. Write a simple C program to generate a random number 
 between 0 and 9. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
        printf("%d\n",rand()%10);
    return 0;
}