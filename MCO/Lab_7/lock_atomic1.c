/************************************************
Using atomic directive

Program Example:
This program creates four threads
Each thread increments a shared variable inside a loop. 
The lock ensures that only one thread at a time can modify the shared variable (preventing Data Race). 
The final value of the shared variable should be equal to the total number of increments across all threads.

***********************************************/

/*** Incrementing a shared variable by 4 threads. Observe your result ***/

#include <omp.h>
#include <stdio.h>

int s1=0; // declaring and initialising shared variable s1 to zero



int main() {
    

    #pragma omp parallel num_threads(4)
    {
        int thread_id = omp_get_thread_num();

        // Each thread increments the shared variable while ensuring mutual exclusion
        for (int i = 0; i < 10000; ++i) 
        {
           
           #pragma omp atomic  //the statement gets executed in an atomic manner without interruption/switch
           		   
            s1++;
	   
           
        }

        printf("Thread %d completed its work!\n", thread_id);
    }

    // Destroy the lock after its use
    omp_destroy_lock(&m1);

    // Display the final value of the shared variable
    printf("Final value of shared_variable: %d\n", s1);

    return 0;
}






