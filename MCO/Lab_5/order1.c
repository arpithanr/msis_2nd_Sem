/*** demo of ordered ***/

#include <omp.h>
#include <stdio.h>
#define len 5

int main()
{
   int a[10], b[10], c[10];

   int i, n, sl_num=1;

   omp_set_num_threads(5);

   printf("Enter 5 numbers for array a: ");
   for (i=0; i<len; i++)
   scanf("%d",&a[i]);

   printf("Enter 5 numbers for array b: ");
   for (i=0; i<len; i++)
   scanf("%d",&b[i]);


#pragma omp parallel for ordered
 for(i=0; i<len; i++)
 { 
                
               
		 printf("%d iteration is done by thread %d\n", i, omp_get_thread_num()); 
                c[i]=a[i]+b[i];
                
		 #pragma omp ordered
                  printf("%d\t", c[i]); 

   

 }


 return 0;

}

