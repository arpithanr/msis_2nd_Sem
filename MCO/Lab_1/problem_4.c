/* 4. Write a simple C program to generate a random number 
 between 1 and 100. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("%d\n",rand()%100);
    return 0;
}