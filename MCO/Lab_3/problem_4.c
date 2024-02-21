/*Create a parallel block. Compute the sum of numbers from
zero to thread_id, and output the sum to the screen. Run
your code and observe the result.*/

#include <stdio.h>
#include <omp.h>

int main()
{
    
    
    #pragma omp parallel
    {
        int sum=0;
        int thread_id = omp_get_thread_num();
        for(int i=0;i<thread_id;i++)
            sum = sum + i;
        printf("Thread id = %d Sum = %d\n",thread_id,sum);
    }
    return 0;
}