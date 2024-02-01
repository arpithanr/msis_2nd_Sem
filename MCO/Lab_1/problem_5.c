// 5. Write a C program to display the current time.

#include <stdio.h>
#include <time.h>

int main()
{
    time_t t;
    time(&t);
    printf("The current time is %s",ctime(&t));
    return 0;

}