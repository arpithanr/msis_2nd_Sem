/*** Demo of Sections directive ***/

#include <stdio.h>
#include <omp.h>

int f1()
{
  for(int i=0; i<5; i++) 
              printf("\n Function f1!\n");
       
  return 0;
}

int main()
{
   
   printf("I'm the main thread with thread number %d\n", omp_get_thread_num());
   

   #pragma omp parallel 
    printf("\nHello from the Parallel region by thread %d .\n", omp_get_thread_num());

   printf("\n\n");

   #pragma omp parallel sections
   {   
     #pragma omp section
     {
       printf("This is the first section executing function f1().\n");
       f1();
       printf("\n Thread number in the first section is :%d\n", omp_get_thread_num());
     }

     #pragma omp section
     {
        printf("\n\nThis is the second section executing a for loop. \n");
        
        for(int i=0; i<5; i++)
	printf("Value of i is: %d\n", i);
        printf("\n Thread number in the second section is :%d\n", omp_get_thread_num());
    }
  }
   
  return 0;
}
