/************************************************
Using locks in OpenMP:

    omp_init_lock initializes the lock.
    omp_set_lock is used to acquire the lock (before accessing the shared resource).
    omp_unset_lock is used to release the lock (after updating the shared resource).
    omp_destroy_lock is used to destroy the lock after its use.


Program Example:
This program creates four threads
Each thread increments a shared variable inside a loop. 
The lock ensures that only one thread at a time can modify the shared variable (preventing Data Race). 
The final value of the shared variable should be equal to the total number of increments across all threads.

***********************************************/
/*** test your code with and without locks ***/

#include <omp.h>
#include <stdio.h>

omp_lock_t m1;   // declaring a lock m1 (like a mutex)
int        s1=0; // declaring and initialising shared variable s1 to zero



int main() {
    // Initialize the lock
    omp_init_lock(&m1);

    #pragma omp parallel num_threads(4)
    {
        int thread_id = omp_get_thread_num();

        // Each thread increments the shared variable while ensuring mutual exclusion
        for (int i = 0; i < 10000; ++i) 
        {
           omp_set_lock(&m1);  // Locking before accessing the shared variable
            s1++;
           omp_unset_lock(&m1);  // Unlocking after updating the shared variable
        }

        printf("Thread %d completed its work!\n", thread_id);
    }

    // Destroy the lock after its use
    omp_destroy_lock(&m1);

    // Display the final value of the shared variable
    printf("Final value of shared_variable: %d\n", s1);

    return 0;
}






